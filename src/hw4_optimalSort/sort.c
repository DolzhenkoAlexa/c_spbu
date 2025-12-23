#include "sort.h"

int sort_array(int array[], int count) {
    int movedCount = 0;
    
    for (int i = 0; i < count - 1; i++) {
        int swapped = 0;  
        
        for (int j = 0; j < count - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                movedCount++;
                swapped = 1;  
            }
        }
        
        if (!swapped) {
            break;  
        }
    }
    
    return movedCount;
}
