// #include <iostream>
// #include <lib/windows.h>
// #include <lib/string.h>
// #include <lib/cstring>
// #include <lib/cstdlib> // Добавлено для функции atoi

// // Подключаем заголовки
// #include "open_winProgramms.h"
// #include "helper_commands.h"
// #include "client_dist/create_newClient.h"
// #include "client_dist/user_clientInfo.h"
// #include "client_dist/delete_client.h"
// #include "user_computerInfo.h"

// using namespace std;

// char user_command[100];

// void q_command () {
//     cout << "\nEnter your command: ";
//     cin.getline(user_command, sizeof(user_command));
// }

// int main () {
//     // Настройка кодировки для русского языка в консоли Windows
//     SetConsoleCP(1251);
//     SetConsoleOutputCP(1251);
    
//     cout << "=============== MyPt Manager ===============" << endl;
//     cout << "Type 'help' to see available commands" << endl;
//     cout << "Type 'exit' to quit the program" << endl;
//     cout << "========================================================" << endl;
    
//     while (true) {
//         q_command ();
//         if (strcmp(user_command, "new client") == 0) {
//             int account_state = create_new_client(new_client_info());
//             if (account_state == 1) {
//                 account_state = create_new_client(new_client_info());
//             } else {
//                 q_command ();
//             }
//         }
//         else if (strcmp(user_command, "my client") == 0) {
//             if (user_client_info() == 1) {
//                 cout<< "Error in giving info"<<endl;
//             }
//         }
//         else if (strcmp(user_command, "delete my client") == 0) {
//             if (delete_client() == 1) {
//                 cout<<"Error in removing your client" << endl;
//             }
//         }
//         else if (strcmp(user_command, "windows tools") == 0) {
//             openning_win_tools();
//         }
//         else if (strcmp(user_command, "my computer") == 0) {
//             print_system();
//         }
//         else if (strcmp(user_command, "help") == 0) {
//             print_commands(); // Показываем список команд с номерами
//             cout << "Enter the number of the command to learn more: ";
//             char help_choice[10];
//             cin.getline(help_choice, sizeof(help_choice));
//             // Преобразуем строку в целое число для switch
//             int choice = atoi(help_choice);
//             switch (choice) { 
//                 case 1:
//                     about_newClient();
//                     break;
//                 case 2:
//                     about_myClient();
//                     break;
//                 case 3:
//                     about_deleteMyClient();
//                     break;
//                 case 4:
//                     about_windowsTools();
//                     break;
//                 case 5:
//                     about_myComputer();
//                     break;
//                 case 6:
//                     about_help();
//                     break;
//                 case 7:
//                     about_exit();
//                     break;
//                 case 8 :
//                     about_exit();
//                     break;
//                 case 9 :
//                     about_exit();
//                     break;
//                 case 10 :
//                     about_exit();
//                     break;
//                 default:
//                     cout << "Invalid help number." << endl;
//                     break;
//                 break;
//             }
//         }
//         else if (strcmp(user_command, "exit") == 0 || strcmp(user_command, "quit") == 0) {
//             cout << "Exiting program..." << endl;
//             break;
//         }
//         else if (strcmp(user_command, "") == 0) {

//         }
//         else {
//             if (strlen(user_command) > 0) { // Игнорируем пустой ввод
//                 cout << "Unknown command. Type 'help' for available commands." << endl;
//             }
//         }
//     }
//     return 0;
// }



#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>

// Подключаем заголовки
#include "open_winProgramms.h"
#include "helper_commands.h"
#include "client_dist/create_newClient.h"
#include "client_dist/user_clientInfo.h"
#include "client_dist/delete_client.h"
#include "user_computerInfo.h"
#include "special_funcs/code_translator.h"
#include "special_funcs/os_advisor.h"
#include "special_funcs/vulnerability_scanner.h"

using namespace std;

char user_command[256];

void q_command() {
    cout << "\nEnter your command: ";
    cin.getline(user_command, sizeof(user_command));
}

// Функция для разбора аргументов команды t
void parse_t_command(const char* input, char* file, char* from_lang, char* to_lang) {
    // Очищаем буферы
    file[0] = '\0';
    from_lang[0] = '\0';
    to_lang[0] = '\0';
<<<<<<< HEAD
    
    // Пропускаем 't' и пробелы
    const char* ptr = input + 1;
    while (*ptr == ' ') ptr++;
    
=======
    // Пропускаем 't' и пробелы
    const char* ptr = input + 1;
    while (*ptr == ' ') ptr++;
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
    // Парсим первый аргумент (файл)
    int i = 0;
    while (*ptr && *ptr != ' ' && *ptr != ',') {
        if (*ptr == ' ') break;
        file[i++] = *ptr++;
    }
    file[i] = '\0';
<<<<<<< HEAD
    
    // Пропускаем разделители
    while (*ptr && (*ptr == ' ' || *ptr == ',')) ptr++;
    
=======
    // Пропускаем разделители
    while (*ptr && (*ptr == ' ' || *ptr == ',')) ptr++;
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
    // Парсим второй аргумент (исходный язык)
    i = 0;
    while (*ptr && *ptr != ' ' && *ptr != ',') {
        if (*ptr == ' ') break;
        from_lang[i++] = *ptr++;
    }
    from_lang[i] = '\0';
<<<<<<< HEAD
    
    // Пропускаем разделители
    while (*ptr && (*ptr == ' ' || *ptr == ',')) ptr++;
    
=======
    // Пропускаем разделители
    while (*ptr && (*ptr == ' ' || *ptr == ',')) ptr++;
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
    // Парсим третий аргумент (целевой язык)
    i = 0;
    while (*ptr && *ptr != ' ' && *ptr != ',') {
        if (*ptr == ' ') break;
        to_lang[i++] = *ptr++;
    }
    to_lang[i] = '\0';
}

int main() {
    // Настройка кодировки для консоли Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
<<<<<<< HEAD
    
=======
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
    cout << "=============== MyPt Manager ===============" << endl;
    cout << "Type 'help' to see available commands" << endl;
    cout << "Type 'exit' to quit the program" << endl;
    cout << "=============================================" << endl;
<<<<<<< HEAD
    
    while (true) {
        q_command();
        
=======
    while (true) {
        q_command();
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
        // Пропускаем пустой ввод
        if (strlen(user_command) == 0) {
            continue;
        }
<<<<<<< HEAD
        
=======
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
        // Проверяем команду t с аргументами
        if (strncmp(user_command, "t ", 2) == 0 || strcmp(user_command, "t") == 0) {
            if (strcmp(user_command, "t") == 0) {
                cout << "Error: Not enough arguments." << endl;
                cout << "Usage: t <source_file> <source_lang> <target_lang>" << endl;
                cout << "Example: t mycode.cpp c++ python" << endl;
            } else {
                char file[100], from_lang[50], to_lang[50];
                parse_t_command(user_command, file, from_lang, to_lang);
<<<<<<< HEAD
                
=======
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
                if (strlen(file) > 0 && strlen(from_lang) > 0 && strlen(to_lang) > 0) {
                    char* argv[4] = {(char*)"t", file, from_lang, to_lang};
                    t_command(4, argv);
                } else {
                    cout << "Error: Invalid arguments format." << endl;
                    cout << "Usage: t <source_file> <source_lang> <target_lang>" << endl;
                }
            }
        }
        else if (strcmp(user_command, "os-choise") == 0 || strcmp(user_command, "os-choice") == 0) {
            os_choise();
        }
        else if (strcmp(user_command, "scanc") == 0) {
            scanc();
        }
        else if (strcmp(user_command, "new client") == 0) {
            int account_state = new_client_info();
            if (account_state == 0) {
                create_new_client(0);
            } else {
                cout << "Client creation cancelled." << endl;
            }
        }
        else if (strcmp(user_command, "my client") == 0) {
            if (user_client_info() != 0) {
                cout << "Error: Could not retrieve client information." << endl;
            }
        }
        else if (strcmp(user_command, "delete my client") == 0) {
            print_waring_remove();
        }
        else if (strcmp(user_command, "windows tools") == 0) {
            openning_win_tools();
        }
        else if (strcmp(user_command, "my computer") == 0) {
            print_system();
        }
        else if (strcmp(user_command, "help") == 0) {
            print_commands();
<<<<<<< HEAD
            
            cout << "\n=== Additional Commands ===" << endl;
            cout << "8. t <file> <from> <to> - Translate code between languages" << endl;
            cout << "9. os-choise - OS recommendation based on your needs" << endl;
            cout << "10. scanc - Scan computer for vulnerabilities" << endl;
            
=======
            cout << "9. os-choise - OS recommendation based on your needs" << endl;
            cout << "10. scanc - Scan computer for vulnerabilities" << endl;
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
            cout << "\nEnter the number of the command to learn more (or 0 for main menu): ";
            char help_choice[10];
            cin.getline(help_choice, sizeof(help_choice));
            
            int choice = atoi(help_choice);
            switch (choice) {
                case 1:
                    about_newClient();
                    break;
                case 2:
                    about_myClient();
                    break;
                case 3:
                    about_deleteMyClient();
                    break;
                case 4:
                    about_windowsTools();
                    break;
                case 5:
                    about_myComputer();
                    break;
                case 6:
                    about_help();
                    break;
                case 7:
                    about_exit();
                    break;
                case 8:
                    cout << "\n=== Code Translator (t) ===" << endl;
                    cout << "Translates code between programming languages." << endl;
                    cout << "Usage: t <source_file> <source_lang> <target_lang>" << endl;
                    cout << "Example: t script.py python c++" << endl;
                    cout << "Supported languages: python, c++, pascal, java, c, c#" << endl;
                    break;
                case 9:
                    cout << "\n=== OS Advisor (os-choise) ===" << endl;
                    cout << "Asks questions about your needs and recommends the best OS." << endl;
                    cout << "Just type 'os-choise' and answer the questions." << endl;
                    break;
                case 10:
                    cout << "\n=== Vulnerability Scanner (scanc) ===" << endl;
                    cout << "Scans your computer for security vulnerabilities." << endl;
                    cout << "Checks for: antivirus status, open ports, UAC settings, weak passwords." << endl;
                    cout << "Type 'scanc' to start scanning." << endl;
                    break;
                default:
                    if (choice != 0) {
                        cout << "Invalid help number." << endl;
                    }
                    break;
            }
        }
        else if (strcmp(user_command, "exit") == 0 || strcmp(user_command, "quit") == 0) {
            cout << "Exiting program..." << endl;
            break;
        }
        else {
            cout << "Unknown command. Type 'help' for available commands." << endl;
        }
    }
    return 0;
}