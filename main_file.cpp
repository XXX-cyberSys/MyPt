#include <iostream>
#include <lib/windows.h>
#include <lib/string.h>
#include <lib/cstring>
#include <lib/cstdlib> // Добавлено для функции atoi

// Подключаем заголовки
#include "open_winProgramms.h"
#include "helper_commands.h"
#include "client_dist/create_newClient.h"
#include "client_dist/user_clientInfo.h"
#include "client_dist/delete_client.h"
#include "client_dist/user_computerInfo.h"

using namespace std;

char user_command[100];

void q_command () {
    cout << "\nEnter your command: ";
    cin.getline(user_command, sizeof(user_command));
}

int main () {
    // Настройка кодировки для русского языка в консоли Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "=============== MyPt Manager ===============" << endl;
    cout << "Type 'help' to see available commands" << endl;
    cout << "Type 'exit' to quit the program" << endl;
    cout << "========================================================" << endl;
    
    while (true) {
        q_command ();
        if (strcmp(user_command, "new client") == 0) {
            int account_state = create_new_client(new_client_info());
            if (account_state == 1) {
                account_state = create_new_client(new_client_info());
            } else {
                q_command ();
            }
        }
        else if (strcmp(user_command, "my client") == 0) {
            if (user_client_info() == 1) {
                cout<< "Error in giving info"<<endl;
            }
        }
        else if (strcmp(user_command, "delete my client") == 0) {
            if (delete_client() == 1) {
                cout<<"Error in removing your client" << endl;
            }
        }
        else if (strcmp(user_command, "windows tools") == 0) {
            openning_win_tools();
        }
        else if (strcmp(user_command, "my computer") == 0) {
            print_system();
        }
        else if (strcmp(user_command, "help") == 0) {
            print_commands(); // Показываем список команд с номерами
            cout << "Enter the number of the command to learn more: ";
            char help_choice[10];
            cin.getline(help_choice, sizeof(help_choice));
            // Преобразуем строку в целое число для switch
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
                default:
                    cout << "Invalid help number." << endl;
                    break;
                break;
            }
        }
        else if (strcmp(user_command, "exit") == 0 || strcmp(user_command, "quit") == 0) {
            cout << "Exiting program..." << endl;
            break;
        }
        else {
            if (strlen(user_command) > 0) { // Игнорируем пустой ввод
                cout << "Unknown command. Type 'help' for available commands." << endl;
            }
        }
    }
    return 0;
}
