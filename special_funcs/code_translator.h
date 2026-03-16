#ifndef CODE_TRANSLATOR_H
#define CODE_TRANSLATOR_H

#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <cstring>
#include <cctype>

// Function to get file extension by language
const char* get_file_extension(const char* language) {
    if (strcmp(language, "python") == 0)
        return ".py";
    else if (strcmp(language, "c++") == 0 || strcmp(language, "cpp") == 0)
        return ".cpp";
    else if (strcmp(language, "pascal") == 0)
        return ".pas";
    else if (strcmp(language, "java") == 0)
        return ".java";
    else if (strcmp(language, "c") == 0)
        return ".c";
    else if (strcmp(language, "c#") == 0 || strcmp(language, "csharp") == 0)
        return ".cs";
    else if (strcmp(language, "javascript") == 0 || strcmp(language, "js") == 0)
        return ".js";
    else if (strcmp(language, "html") == 0)
        return ".html";
    else if (strcmp(language, "css") == 0)
        return ".css";
    else
        return ".txt";
}

// Function to create prompt for AI/code translator
void create_translation_prompt(const char* source_file, const char* from_lang, 
                               const char* to_lang, char* prompt_buffer, int buffer_size) {
    char filename[256];
    strcpy(filename, source_file);
    
    // Remove extension if exists
    char* dot = strrchr(filename, '.');
    if (dot) *dot = '\0';
    
    snprintf(prompt_buffer, buffer_size,
        "Translate the code from %s to %s. The source code is in file: %s\n"
        "Save the result to file: %s_translated%s\n\n"
        "Please preserve the program structure, comments (translate them to English or keep original, "
        "preserving meaning) and ensure correct syntax for the target language.",
        from_lang, to_lang, source_file, filename, get_file_extension(to_lang));
}

int t_command(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Error: Not enough arguments.\n");
        printf("Usage: t <source_file> <source_language> <target_language>\n");
        printf("Example: t mycode.cpp c++ python\n");
        printf("Supported languages: python, c++, c, c#, java, pascal, javascript, html, css\n");
        return 1;
    }
    
    const char* source_file = argv[1];
    const char* from_lang = argv[2];
    const char* to_lang = argv[3];
    
    // Check if source file exists
    FILE* test = fopen(source_file, "r");
    if (!test) {
        printf("Error: File '%s' not found!\n", source_file);
        return 1;
    }
    fclose(test);
    
    printf("\n========================================\n");
    printf("CODE TRANSLATOR\n");
    printf("========================================\n");
    printf("Source file: %s\n", source_file);
    printf("Source language: %s\n", from_lang);
    printf("Target language: %s\n", to_lang);
    printf("========================================\n");
    
    // Create output filename
    char output_file[256];
    char base_name[256];
    strcpy(base_name, source_file);
    
    // Remove extension
    char* dot = strrchr(base_name, '.');
    if (dot) *dot = '\0';
    
    snprintf(output_file, sizeof(output_file), "%s_translated%s", 
             base_name, get_file_extension(to_lang));
    
    printf("Output file: %s\n", output_file);
    printf("========================================\n");
    
    // Read source code
    FILE* source = fopen(source_file, "r");
    if (!source) {
        printf("Error opening source file\n");
        return 1;
    }
    
    // Determine file size
    fseek(source, 0, SEEK_END);
    long file_size = ftell(source);
    fseek(source, 0, SEEK_SET);
    
    // Allocate memory for content
    char* code_content = (char*)malloc(file_size + 1);
    if (!code_content) {
        printf("Memory allocation error\n");
        fclose(source);
        return 1;
    }
    
    // Read file
    size_t read_size = fread(code_content, 1, file_size, source);
    code_content[read_size] = '\0';
    fclose(source);
    
    // Create prompt for translation
    char prompt[2048];
    snprintf(prompt, sizeof(prompt),
        "You are a professional code translator. Translate the following code from %s to %s.\n"
        "Preserve the program logic, structure, and comments (translate comments to English, "
        "keeping the meaning). Use correct syntax for the target language.\n\n"
        "Source code (%s):\n%s\n\n"
        "Translated code (%s):\n",
        from_lang, to_lang, from_lang, code_content, to_lang);
    
    // Create temporary file with prompt
    FILE* prompt_file = fopen("translation_prompt.txt", "w");
    if (prompt_file) {
        fprintf(prompt_file, "%s", prompt);
        fclose(prompt_file);
        printf("✓ Translation prompt saved to 'translation_prompt.txt'\n");
    }
    
    // Create HTML guide file
    FILE* html_guide = fopen("translation_guide.html", "w");
    if (html_guide) {
        fprintf(html_guide, 
            "<!DOCTYPE html>\n"
            "<html>\n"
            "<head><title>Code Translation Guide</title></head>\n"
            "<body style='font-family: Arial; max-width: 800px; margin: 20px auto;'>\n"
            "<h1>Code Translation Guide</h1>\n"
            "<p><strong>Source file:</strong> %s</p>\n"
            "<p><strong>Translate from %s to %s</strong></p>\n"
            "<h2>Translation Methods:</h2>\n"
            "<ol>\n"
            "<li>Use online services (ChatGPT, Claude, etc.) with the prompt from translation_prompt.txt</li>\n"
            "<li>Use specialized tools: ChatGPT Code Interpreter, GitHub Copilot</li>\n"
            "<li>Copy the code and use any online code translator</li>\n"
            "</ol>\n"
            "<h2>Source Code:</h2>\n"
            "<pre style='background: #f4f4f4; padding: 10px; border-radius: 5px; overflow-x: auto;'>\n"
            "%s\n"
            "</pre>\n"
            "<p>After translation, save the result to: <strong>%s</strong></p>\n"
            "</body>\n"
            "</html>\n",
            source_file, from_lang, to_lang, code_content, output_file);
        fclose(html_guide);
        printf(" HTML guide saved to 'translation_guide.html'\n");
    }
    
    // Open source file in notepad for copying
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "start notepad %s", source_file);
    system(cmd);
    
    printf("\nSource file opened in Notepad.\n");
    printf("Translation prompt saved for AI.\n");
    printf("HTML guide created with instructions.\n");
    printf("\nRecommendations:\n");
    printf("1. Copy the code from Notepad\n");
    printf("2. Use ChatGPT or another AI for translation\n");
    printf("3. Save the result to file: %s\n", output_file);
    printf("========================================\n");
    
    free(code_content);
    return 0;
}

#endif // CODE_TRANSLATOR_H