#include <stdio.h>
#include <string.h>

int main() 
{
    char str[512];
    char substr[512];
    
    printf("Введите строку: \n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  
    // Удаляем символ новой строки
    // Потому что fgets() включает символ новой строки в считанную строку
    
    printf("Введите подстроку: \n");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0';
    
    int count = 0;
    int pos = 0;
    while (strstr(str + pos, substr)) {
        count++;
        pos++;
    }
    
    printf("%d\n", count);
    return 0;
}
