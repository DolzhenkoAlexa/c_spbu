#include <stdio.h>

int main()
{
    int count[28] = {0};
    // Считаем, сколько троек цифр имеют каждую сумму
    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                // увеличиваем на 1 значение ячейки массива под номером, равным сумме тройки
                count[a + b + c]++;
            }
        }
    }
    
    int result = 0;
    for (int sum = 0; sum <= 27; sum++) {
        // Берем все 27 возможных "сумм"
        // 27 потому что максимум 9+9+9=27
        result = result + (count[sum] * count[sum]);
    }
    printf("Общее количество счастливых билетов со всеми суммами: %d\n", result);
    return 0;
}

