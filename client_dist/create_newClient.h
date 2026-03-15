#include <cstdio>
#include <lib/windows.h>
#include <lib/cstdlib>
#include <lib/string.h>

// универсальная функция (должна быть объявлена выше или в заголовочном файле)
int save_to_file(const char* data, const char* filename, const char* folder) {
    char full_path[256];
    char cmd[256];
    sprintf(cmd, "mkdir %s 2> nul", folder);
    system(cmd);
    sprintf(full_path, "%s/%s", folder, filename);
    FILE *file = fopen(full_path, "w");
    if (file == NULL) return 1;
    fprintf(file, "%s\n", data);
    fclose(file);
    return 0;
}

int new_client_info() {
    char user_name[100];
    char user_password[100];
    char user_create_answer[10];
    char buffer[256];
    printf("==================== New client-account =======================\n");
    printf("Settings at your new account:\n");
    // 1. Ввод логина (крутим цикл, пока не введут хоть что-то)
    while (1) {
        printf("   Enter login (up to 100): ");
        if (scanf("%99s", user_name) == 1 && strlen(user_name) > 0) {
            break; 
        }
        printf("   Error: Login cannot be empty!\n");
    }
    // 2. Ввод пароля
    while (1) {
        printf("   Enter password (up to 100): ");
        if (scanf("%99s", user_password) == 1 && strlen(user_password) > 0) {
            break;
        }
        printf("   Error: Password cannot be empty!\n");
    }
    // 3. Подтверждение
    printf("   We can take info about your device and write it to your account.\n");
    printf("Do you want to create a new account? (yes/no): ");
    scanf("%9s", user_create_answer);
    if (user_create_answer[0] == 'y' || user_create_answer[0] == 'Y') {
        // Записываем логин
        sprintf(buffer, "login: %s", user_name);
        save_to_file(buffer, "account_login.txt", "user_settings_files");
        // Записываем пароль
        sprintf(buffer, "password: %s", user_password);
        save_to_file(buffer, "account_password.txt", "user_settings_files");
        printf("==============================================================\n");
        printf("Success: Data saved to 'user_settings_files' folder!\n");
        return 0; // Успешное завершение
    } 
    printf("Operation cancelled. Your account wasn't created.\n");
    return 1; // Отказ пользователя
}


int create_new_client (int user_state) {
    if (user_state == 0) {
        printf ("==================== creating new client... =======================");
        printf ("We created a new account for you.\n Files with your info save in folder with name 'user_settings_file' on your computer");
        printf ("If you delite this folder, your client-account delite\n\n");
        printf("========================= MyPt ===============================\n");
        return 0;
    } else {
        printf ("An error occurred while creating the client\n"); //ошибка вылета, клиента создать не удалось
        return 1;
    }
}