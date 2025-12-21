#include <stdio.h>

// Функция для обращения порядка элементов в массиве
void reverser(int array[], int start, int end) 
{
    while (start < end) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}


int main() 
{
    int m, n, arrayLen;
    
    // Ввод размеров
    printf("Введите m: \n");
    scanf("%d", &m);
    printf("Введите n: \n");
    scanf("%d", &n);
    arrayLen = m + n;
    int array[arrayLen];
    
    // Ввод элементов массива
    printf("Введите элементы массива, в количестве m+n:\n");
    for (int i = 0; i < arrayLen; i++) {
        scanf("%d", &array[i]);
    }
    
    // Перестановка
    // 1. Обращаем весь массив в обратный порядок. 
    reverser(array, 0, m + n - 1);
    // 2. Обращаем первую часть 
    reverser(array, 0, n - 1);
    // 3. Обращаем вторую часть
    reverser(array, n, m + n - 1);
    
    // Пример: 0 1 3 5 7 9 11 (m=3, n=4) 
    // 1. 11 9 7 5 3 1 0 
    // 2. Так как n=4, меняем первые 4 - 5 7 9 11 
    // 3. Так как m=3, то последние 3 - 0 1 3
    // Итог: 5 7 9 11 0 1 3
    
    // Вывод результата
    printf("После перестановки: ");
    for (int i = 0; i < arrayLen; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
