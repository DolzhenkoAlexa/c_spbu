#include <stdio.h>

// Объявление функции
extern int sort_array(int array[], int count);

// Основной код - объявление массива на 100 чисел, создание счетчика, чтобы знать со сколькими числами надо будет работать, чтение чисел через for с scanf и вывод
int main() {
    int array[100];
    int count = 0;
    
    int i = 0;
    while (i < 100 && scanf("%d", &array[i]) == 1) {
        i++;
        count++;
    }
    
    int moved = sort_array(array, count);
    
    printf("Отсортированный массив:");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
