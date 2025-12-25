#include <stdio.h>
#include "counter.h"

int main()
{
    int n, m;
    printf("Введите n и m: ");
    scanf("%d %d", &n, &m);

    int result = counter(n, m);
    
    if (result != -1) {
        printf("Нужная позиция: %d\n", result);
    } else {
        printf("Ошибка в вычислениях\n");
    }

    return 0;
}
