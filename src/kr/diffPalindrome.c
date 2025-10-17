//
// Created by sasha on 17.10.2025.
//

//Напечатать на экран все из диапазона [1;n],
//которые являются палиндромами в двоичной записи. Выводить в десятичной системе счисления.

#include <stdio.h>
#include <string.h>

int systemChangerTo2(int n) {
    int binaryNum[1000]; //Массив для числа во вторичной
    char charBinaryNum[1000]; // Массив для числа во вторичной, но в виде строки
    int i = 0;
    int len = 0;

    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
        len = i; // Длина массива
    }

    for (i = 0; i < len; i++) {
        charBinaryNum[i] = binaryNum[i] + '0';
    }

    int left = 0;
    int right = strlen(charBinaryNum) - 1;

    while (left <= right) {
        if (charBinaryNum[left] == charBinaryNum[right]) {
            left++;
            right--;
        } else {
            return 0;
        }
        if (left > right) {
            return 1;
        }
    }
}




int main(void) {
    int n = 0;

    printf("Введите n \n");
    scanf("%d",&n);

    int arr[n];
    int num = 0;

    for (int i = 0; i < n; i++) {
        arr[i] = num;
        num++;

        if (systemChangerTo2(num) == 1) {
            printf("%d\n", num);
        }
    }
    

    return 0;
}
