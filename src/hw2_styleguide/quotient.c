#include <stdio.h>
#include <stdlib.h>

int findQuotient(int a, int b)
{
    if (b == 0) {
        printf("Нельзя делить на ноль!\n");
        return 0;
    }
    
    int q = 0;
    while ((q + 1) * abs(b) <= abs(a)) {
        q++;
    }
    
    if (a * b < 0) {
        return -q;
    }
    return q;
}

int main()
{
    int a, b;
    printf("Введите два целых a и b, чтобы найти q (a = b*q): \n");
    scanf("%d %d", &a, &b);
    
    int q = findQuotient(a, b);
    if (b != 0) {
        printf("Неполное частное от деления q: %d\n", q);
    }
    return 0;
}
