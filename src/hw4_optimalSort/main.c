#include <stdio.h>
#include "sort.h"

int main()
{
    int array[100];
    int count = 0;

    while (count < 100 && scanf("%d", &array[count]) == 1) {
        count++;
    }

    int moved = sortArray(array, count);

    for (int i = 0; i < count; i++) {
        // Чтоб удобнее глазками считать колво перестановок
        printf("%d ", array[i]); 
    }
    printf("\n");

    printf("%d ", moved);
    return moved;
}
