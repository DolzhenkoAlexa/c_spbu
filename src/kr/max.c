//
// В массиве целых чисел найти число, сумма цифр которого была бы наибольшей.
// Если таких чисел несколько, вывести на экран все эти числа.
//

#include <stdio.h>

// Функция нахождения максимальной суммы
int finder(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int tempSum = 0; // Временная сумма для каждого отдельно взятого числа
        int temp = arr[i];

        while (temp / 10 != 0) { // "Резатель числа", режем - пока оно не станет нулевым, прибавляем хвостик к сумме
            tempSum += (temp % 10);
            temp = temp/10;
            printf("Sum %d\n", tempSum);
            printf("%d \n", temp);
        }
        tempSum = temp + tempSum;
        printf("Sum %d\n", tempSum);

        if (tempSum > sum) {
            sum = tempSum;
        }
    }
    return sum;
}

int main(void) {
    int size = 0;

    printf("Введите колво чисел в массиве (len) \n");
    scanf("%d",&size);

    int arr[size];

    printf("Введите сами числа в массив \n");
    for (int i = 0; i < size; i++) {
        scanf("%d",&arr[i]);
    }

    int maxSum = finder(arr, size);

    printf("\n");
    printf("Max sum of numbers %d", maxSum);
    return 0;
}
