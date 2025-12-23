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

    return moved;
}
