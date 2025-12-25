#include "complexParenthese.h"

#include <stdio.h>
#include <string.h>
#include "stack.h"

int checkBrackets(char str[])
{
    Stack stack;
    init_stack(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '('
            || str[i] == '['
            || str[i] == '{') {
            push(&stack, str[i]);
        } else if (str[i] == ')'
            || str[i] == ']'
            || str[i] == '}') {
            if (stackEmptiness(&stack)) {
                return 0; // Обрабатываем случай, когда одна закрывающая и без открывающих
            }
            char lastElem = pop(&stack);

            // проверяем соответствие скобок (они должны быть одного вида, если встретилась закрывающаяся)
            if ((lastElem == '(' && str[i] != ')')
                || (lastElem == '[' && str[i] != ']')
                || (lastElem == '{' && str[i] != '}'))
                return 0;
            // Если, например, встретились last == '{' и str[i] == '}', то все верно, идем дальше.
            // В стек не добавляется новый элемент, а прошлый удаляется через pop
        }
    }
    return stackEmptiness(&stack);
}

int main()
{
    char str[1000];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    if (checkBrackets(str)) {
        printf("Сбалансирована!\n");
    } else {
        printf("Неслабалансирована\n");
    }

    return 0;
}
