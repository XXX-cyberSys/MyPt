#include <cstdio>
#include <lib/windows.h>
#include <lib/cstdlib>
#include <lib/string.h>

// проверяем результат выполнения команды.
int delete_client() {
    // Удаляем файлы. Если папка пуста, можно удалить и саму папку.
    int res1 = system("del /Q \"user_settings_files\\account_login.txt\" 2>nul");
    int res2 = system("del /Q \"user_settings_files\\account_password.txt\" 2>nul");
    
    if (res1 == 0 && res2 == 0) {
        printf("\n[Success] Client files deleted.\n");
        return 0;
    } else {
        printf("\n[Error] Files not found or already deleted.\n");
        return 1;
    }
}

void print_waring_remove() {
    char user_answer[10]; // Увеличим буфер для безопасности
    
    printf("\n======================== Delete client ==========================\n");
    printf("Are you sure you want to delete client-account? (yes/no): ");
    scanf("%9s", user_answer);

    if (user_answer[0] == 'y' || user_answer[0] == 'Y') {
        delete_client();
    } else {
        printf("Deletion cancelled.\n");
    }
}