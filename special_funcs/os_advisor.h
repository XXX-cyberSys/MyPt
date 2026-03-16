#ifndef OS_ADVISOR_H
#define OS_ADVISOR_H

#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <cstring>
#include <cctype>

// Structure for OS characteristics
typedef struct {
    const char* name;
    const char* description;
    int gaming_score;        // 0-10
    int productivity_score;  // 0-10  
    int ease_score;         // 0-10
    int security_score;     // 0-10
    int customization_score; // 0-10
    const char* best_for;
} OS_Info;

// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to convert string to lowercase
void to_lowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int os_choise() {
    printf("\n=============== OS ADVISOR ===============\n");
    printf("Answer a few questions to find your ideal OS\n");
    printf("============================================\n\n");
    // OS data initialization
    OS_Info os_list[] = {
        {"Windows 11", "Modern OS from Microsoft with new interface", 
         9, 8, 9, 7, 6, "gaming, everyday tasks, office work"},
        {"Windows 10", "Time-tested stable OS", 
         8, 8, 9, 7, 7, "gaming, compatibility, stability"},
        {"Ubuntu", "Popular Debian-based Linux distribution", 
         5, 9, 6, 9, 9, "programming, servers, security"},
        {"Linux Mint", "User-friendly Linux for beginners", 
         4, 8, 8, 9, 8, "starting with Linux, home use"},
        {"macOS", "Apple OS for Mac computers", 
         6, 9, 8, 8, 5, "creative work, design, Apple development"},
        {"Fedora", "Modern Linux with latest software", 
         5, 9, 6, 9, 8, "developers, enthusiasts"},
        {"Arch Linux", "Flexible DIY OS for advanced users", 
         6, 9, 3, 8, 10, "maximum customization, learning Linux"},
        {"Pop!_OS", "Linux for gamers and developers", 
         7, 9, 7, 8, 8, "gaming on Linux, scientific computing"},
        {"FreeBSD", "Advanced UNIX-like operating system", 
         3, 8, 4, 9, 7, "servers, networking, security"}
    };
    int os_count = sizeof(os_list) / sizeof(os_list[0]);
    // Scores for different criteria
    int gaming_score = 0;
    int productivity_score = 0;
    int ease_score = 0;
    int security_score = 0;
    int customization_score = 0;
    int total_questions = 0;
    char answer[50];
    // Question 1: Purpose
    printf("1. What will you use the computer for?\n");
    printf("   a) Gaming only\n");
    printf("   b) Work/Study\n");
    printf("   c) Both gaming and work\n");
    printf("   d) Programming/Server\n");
    printf("   Your choice (a/b/c/d): ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;
    to_lowercase(answer);
    if (strcmp(answer, "a") == 0) {
        gaming_score += 10;
        productivity_score += 2;
        ease_score += 5;
        total_questions++;
    } else if (strcmp(answer, "b") == 0) {
        gaming_score += 2;
        productivity_score += 10;
        ease_score += 8;
        total_questions++;
    } else if (strcmp(answer, "c") == 0) {
        gaming_score += 8;
        productivity_score += 8;
        ease_score += 7;
        total_questions++;
    } else if (strcmp(answer, "d") == 0) {
        gaming_score += 1;
        productivity_score += 10;
        ease_score += 4;
        customization_score += 8;
        security_score += 8;
        total_questions++;
    }
    // Question 2: Experience level
    printf("\n2. What is your experience level with computers?\n");
    printf("   a) Beginner\n");
    printf("   b) Intermediate user\n");
    printf("   c) Professional/Programmer\n");
    printf("   d) Enthusiast (love tweaking everything)\n");
    printf("   Your choice (a/b/c/d): ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;
    to_lowercase(answer);
    if (strcmp(answer, "a") == 0) {
        ease_score += 10;
        gaming_score += 2;
        total_questions++;
    } else if (strcmp(answer, "b") == 0) {
        ease_score += 6;
        customization_score += 4;
        total_questions++;
    } else if (strcmp(answer, "c") == 0) {
        productivity_score += 5;
        customization_score += 5;
        security_score += 5;
        total_questions++;
    } else if (strcmp(answer, "d") == 0) {
        customization_score += 10;
        ease_score -= 2;
        total_questions++;
    }
    // Question 3: Security importance
    printf("\n3. How important is security to you?\n");
    printf("   a) Not very (antivirus is enough)\n");
    printf("   b) Important, but not at the expense of convenience\n");
    printf("   c) Critically important\n");
    printf("   Your choice (a/b/c): ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;
    to_lowercase(answer);
    if (strcmp(answer, "a") == 0) {
        security_score += 2;
        total_questions++;
    } else if (strcmp(answer, "b") == 0) {
        security_score += 5;
        ease_score += 2;
        total_questions++;
    } else if (strcmp(answer, "c") == 0) {
        security_score += 10;
        ease_score -= 2;
        total_questions++;
    }
    // Question 4: Hardware
    printf("\n4. What hardware do you have?\n");
    printf("   a) Old/weak PC\n");
    printf("   b) Mid-range PC\n");
    printf("   c) Gaming PC\n");
    printf("   d) Mac (Apple)\n");
    printf("   Your choice (a/b/c/d): ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;
    to_lowercase(answer);
    if (strcmp(answer, "a") == 0) {
        // For old hardware, prefer Linux or older Windows
        for (int i = 0; i < os_count; i++) {
            if (strcmp(os_list[i].name, "Linux Mint") == 0) os_list[i].gaming_score += 3;
            if (strcmp(os_list[i].name, "Ubuntu") == 0) os_list[i].gaming_score += 3;
            if (strcmp(os_list[i].name, "Windows 10") == 0) os_list[i].gaming_score += 2;
            if (strcmp(os_list[i].name, "Windows 11") == 0) os_list[i].gaming_score -= 5;
        }
        total_questions++;
    } else if (strcmp(answer, "b") == 0) {
        // Mid-range - everything works
        total_questions++;
    } else if (strcmp(answer, "c") == 0) {
        gaming_score += 5;
        total_questions++;
    } else if (strcmp(answer, "d") == 0) {
        printf("\n✅ You have a Mac - ideal choice: macOS\n");
        printf("========================================\n");
        return 0;
    }
    // Question 5: Software needs
    printf("\n5. What software do you need?\n");
    printf("   a) Browser and office only\n");
    printf("   b) Specific software (Adobe, CAD, etc.)\n");
    printf("   c) Games\n");
    printf("   d) Development tools\n");
    printf("   Your choice (a/b/c/d): ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;
    to_lowercase(answer);
    
    if (strcmp(answer, "a") == 0) {
        // Any OS works
        total_questions++;
    } else if (strcmp(answer, "b") == 0) {
        printf("\n⚠️  If you need specific Windows software, better choose Windows.\n");
        for (int i = 0; i < os_count; i++) {
            if (strstr(os_list[i].name, "Windows") != NULL) {
                os_list[i].productivity_score += 5;
            }
        }
        total_questions++;
    } else if (strcmp(answer, "c") == 0) {
        gaming_score += 8;
        total_questions++;
    } else if (strcmp(answer, "d") == 0) {
        productivity_score += 3;
        customization_score += 3;
        total_questions++;
    }
    // Normalize user scores
    if (total_questions > 0) {
        gaming_score = gaming_score / total_questions;
        productivity_score = productivity_score / total_questions;
        ease_score = ease_score / total_questions;
        security_score = security_score / total_questions;
        customization_score = customization_score / total_questions;
    }
    // Calculate compatibility with each OS
    float compatibility[os_count];
    float max_compat = -9999;
    int best_os_index = 0;
    printf("\n============= ANALYSIS RESULTS =============\n");
    printf("Your priorities (on a 10-point scale):\n");
    printf("Gaming: %d/10\n", gaming_score);
    printf("Productivity: %d/10\n", productivity_score);
    printf("Ease of use: %d/10\n", ease_score);
    printf("Security: %d/10\n", security_score);
    printf("Customization: %d/10\n", customization_score);
    printf("==============================================\n\n");
    printf("OS that suit you:\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < os_count; i++) {
        // Calculate compatibility (Euclidean distance in multidimensional space)
        float gaming_diff = gaming_score - os_list[i].gaming_score;
        float prod_diff = productivity_score - os_list[i].productivity_score;
        float ease_diff = ease_score - os_list[i].ease_score;
        float sec_diff = security_score - os_list[i].security_score;
        float cust_diff = customization_score - os_list[i].customization_score;
        // Smaller distance is better
        float distance = gaming_diff * gaming_diff + 
                         prod_diff * prod_diff + 
                         ease_diff * ease_diff + 
                         sec_diff * sec_diff + 
                         cust_diff * cust_diff;
        compatibility[i] = 1000.0f / (distance + 1); // Convert to compatibility score
        compatibility[i] = (compatibility[i] > 100) ? 100 : compatibility[i];
        printf("%d. %s\n", i+1, os_list[i].name);
        printf("   Compatibility: %.0f%%\n", compatibility[i]);
        printf("   Description: %s\n", os_list[i].description);
        printf("   Best for: %s\n", os_list[i].best_for);
        printf("   Rating: Gaming:%d/10 | Work:%d/10 | Ease:%d/10 | Security:%d/10\n", 
               os_list[i].gaming_score, os_list[i].productivity_score, 
               os_list[i].ease_score, os_list[i].security_score);
        printf("----------------------------------------------\n");
        if (compatibility[i] > max_compat) {
            max_compat = compatibility[i];
            best_os_index = i;
        }
    }
    
    printf("\n ** IDEAL CHOICE FOR YOU: %s **\n", os_list[best_os_index].name);
    printf("   Compatibility: %.0f%%\n", compatibility[best_os_index]);
    printf("   %s\n", os_list[best_os_index].description);
    printf("==============================================\n");
    // Additional recommendations
    printf("\n Recommendations:\n");
    if (gaming_score > 7) {
        printf("• For gaming, Windows 10/11 or SteamOS are best\n");
    }
    if (security_score > 7 && ease_score < 5) {
        printf("• Consider Qubes OS or Tails for maximum security\n");
    }
    if (customization_score > 8 && ease_score > 3) {
        printf("• Arch Linux or Gentoo will give you full control over the system\n");
    }
    if (productivity_score > 8 && gaming_score < 3) {
        printf("• For pure productivity, consider FreeBSD or a minimal Linux setup\n");
    }
    
    return 0;
}

#endif // OS_ADVISOR_H