#include "doubleExp.h"
#include <stdio.h>
#include "doubleExp.h"

typedef union DoubleUnion {
    double value;
    unsigned char bytes[8];
} DoubleUnion;

// Получение бита i
static int getBitI(const DoubleUnion *d, int i)
{
    int byte = i / 8;
    int bit  = i % 8;

    // Пролучаем нужный байт и сдвигаем его на позицию 0
    char neededByte = d->bytes[byte];
    char changePosition = neededByte >> bit;

    return changePosition & 1;
}

void doubleExp(double x)
{
    DoubleUnion d;
    d.value = x;

    // Определяем знак
    int signI = getBitI(&d, 63);
    char sign;
    if (signI)
        sign = '-';
    else
        sign = '+';

    int exp = 0;
    for (int i = 62; i >= 52; i--) {
        exp = (exp << 1) | getBitI(&d, i);
    }

    // Достаем мантиссу
    long long mantissaBits = 0;
    for (int i = 51; i >= 0; i--) {
        mantissaBits = (mantissaBits << 1) | getBitI(&d, i);
    }

    // Проверка для INF и NaN
    if (exp == 2047) {
        if (mantissaBits == 0) {
            printf("%cINF\n", sign);
        } else {
            printf("NaN\n");
        }
        return;
    }

    // Проверка для +0 и -0
    if (exp == 0 && mantissaBits == 0) {
        printf("%c0\n", sign);
        return;
    }

    double mantissa = 1.0;
    double fractionPart = 0.5;
    for (int i = 51; i >= 0; i--) {
        if (getBitI(&d, i)) {
            mantissa += fractionPart;
        }
        fractionPart /= 2.0;
    }

    // Так как в double порядок смещен на 1023, то получаем настоящий вычетанием
    int power = exp - 1023;

    printf("Результат: %c%.20f*2^%d\n", sign, mantissa, power);
}
