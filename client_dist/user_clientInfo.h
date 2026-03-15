#include <cstdio>
#include <lib/windows.h>
#include <lib/cstdlib>
#include <lib/string.h>

// data - буфер, куда запишем результат, filename - имя файла, folder - папка
int read_from_file(char* data, int buffer_size, const char* filename, const char* folder) {
    char full_path[256];
    // Формируем путь
    sprintf(full_path, "%s/%s", folder, filename);
    // Открываем для чтения ("r")
    FILE *file = fopen(full_path, "r");
    if (file == NULL) {
        return 1; // Файл не найден или ошибка
    }
    // Читаем одну строку целиком
    if (fgets(data, buffer_size, file) != NULL) {
        // Удаляем символ переноса строки \n, если он есть
        data[strcspn(data, "\n")] = 0;
        fclose(file);
        return 0; // Успех
    }
    fclose(file);
    return 2; // Файл пуст
}

int user_client_info() {
    char login[125];
    char password[125];
    const char* folder = "user_settings_files";
    printf("\n--- Account Data ---\n");
    // 1. Читаем и выводим логин
    if (read_from_file(login, sizeof(login), "account_login.txt", folder) == 0) {
        printf("%s\n", login);
    } else {
        printf("Login: [Not Found]\n");
    }
    // 2. Читаем и выводим пароль
    if (read_from_file(password, sizeof(password), "account_password.txt", folder) == 0) {
        printf("%s\n", password);
    } else {
        printf("Password: [Not Found]\n");
    }
    return 0;
}