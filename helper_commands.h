#include <stdio.h>
#include <windows.h>

void print_commands() {
    printf("\n=== Available Commands ===\n");
    printf("1. new client - Create new client with access key\n");
    printf("2. my client - Show client information\n");
    printf("3. delete my client - Delete client data\n");
    printf("4. windows tools - Open Windows applications\n");
    printf("5. my computer - Show system information\n");
    printf("6. help - Show this help message\n");
    printf("7. exit - Exit the program\n\n");
    printf("8. t <file> <from> <to> - Translate code between languages\n");
    printf("9. os-choise - OS recommendation based on your needs\n");
<<<<<<< HEAD
    printf("10. scanc - Scan computer for vulnerabilities\n\n");

=======
    printf("10. scanc - Scan computer for vulnerabilities\n");
>>>>>>> cfe38727812273afa8090a73bbb6f5c85fcd607e
    printf("If you don't know or don't understand about anythink command - write '<command number>'\n\n");
}

void about_newClient() {
    system("start datashets/about_newClient.txt");
}

void about_myClient() {
    system("start datashets/about_myClient.txt");
}

void about_deleteMyClient() {
    system("start datashets/about_deleteMyClient.txt");
}

void about_windowsTools() {
    system("start datashets/about_windowsTools.txt");
}

void about_myComputer() {
    system("start datashets/about_myComputer.txt");
}

void about_help() {
    system("start datashets/about_help.txt");
}

void about_exit() {
    system("start datashets/about_exit.txt");
}