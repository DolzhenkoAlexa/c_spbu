#include <stdio.h>
#include "doubleExp.h"

int main(void)
{
    double x;
    printf("Введите число: ");
    scanf("%lf", &x);
    doubleExp(x);

    return 0;
}
