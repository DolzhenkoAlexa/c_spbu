int sort_array(int* array, int count) {
    int moved_count = 0;
    // сортировка пузырьком
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                moved_count++;
            }
        }
    }
    
    return moved_count;
}
