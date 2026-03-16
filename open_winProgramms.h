#ifndef OPEN_WINPROGRAMS_H
#define OPEN_WINPROGRAMS_H

#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <string.h>

// Объявление функций
//void openning_win_tools();
//void print_commands();
//void print_system();

// Функция открытия Windows инструментов
int openning_win_tools() {
    char user_command[100];
    
    while (1) { // используем 1 вместо true для совместимости с C
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        
        printf("=============== MyPt ===============\n");
        printf("    Write your command...\n");
    
        fgets(user_command, sizeof(user_command), stdin); //enter command
    
        // delete symbol in new line
        user_command[strcspn(user_command, "\n")] = 0;
    
        // word
        if (strcmp(user_command, "open word") == 0 || strcmp(user_command, "word open") == 0) {
            printf("=== Word is opening. Please, don't close terminal... ===\n");
            system("start winword");
        }
        // excel
        else if (strcmp(user_command, "open excel") == 0 || strcmp(user_command, "excel open") == 0) {
            printf("=== Excel is opening. Please, don't close terminal... ===\n");
            system("start excel");
        }
        // powerpoint
        else if (strcmp(user_command, "open pwp") == 0 || strcmp(user_command, "pwp open") == 0) {
            printf("=== PowerPoint is opening. Please, don't close terminal... ===\n");
            system("start powerpnt");
        }
        // exit program
        else if (strcmp(user_command, "exit") == 0 || strcmp(user_command, "close") == 0) {
            break;
        }
        else {
            printf("Unknown command. Type 'exit' to leave.\n");
        }
    }
    return 0;
}
#endif
