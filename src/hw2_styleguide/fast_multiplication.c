#include <stdio.h>
int formula(int a, int b) {
        return (b + a + 1)*(b + 1) - b; // Сокращение начальной формулы до (х^2+x+1)*(x^2+1)-(x^2)
        // Умножение 1: х^2. 
        // Умножение 2: Умножение скобочек
}
    
int main() 
{
    int x = 0;
    printf("Введите значение х:\n");
    scanf("%d", &x);
    int xSquared = x * x;
    int result = formula(x, xSquared);
    
    
    // Вывод результата
    printf("%d", result); 
    return 0;
}
