#include <stdio.h>

int main() 
{
    int n;
    int count = 0;
    
    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &n);
    int array[n];
    
    // Ввод элементов массива
    printf("Введите элементов массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    // Подсчет нулевых элементов
    for (int i = 0; i < n; i++) {
        if (array[i] == 0) {
            count++;
        }
    }
    
    // Вывод результата
    printf("Количество нулевых элементов: %d\n", count);
    return 0;
}
