#include "sort.h"

int sortArray(int array[], int count)
{
    int movedCount = 0;

    // Копия массива
    int original[100];
    for (int i = 0; i < count; i++) {
        original[i] = array[i];
    }

    for (int i = 0; i < count - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < count - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }

    for (int i = 0; i < count; i++) {
        if (array[i] != original[i]) {
            movedCount++;
        }
    }

    return movedCount;
}

