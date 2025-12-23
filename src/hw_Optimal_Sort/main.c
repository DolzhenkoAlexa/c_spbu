#include <stdio.h>
#include "sort.h" 

int main() 
{
    int array[100];
    int count = 0;

    while (count < 100 && scanf("%d", &array[count]) == 1) {
        count++;
    }

    int moved = sort_array(array, count);

    return moved;
}
