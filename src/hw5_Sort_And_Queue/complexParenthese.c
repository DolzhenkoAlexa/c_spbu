//
// Created by sasha on 23.10.2025.
//

#include "complexParenthese.h"

#include <stdio.h>
#include <string.h>
#include "stack.h"

int checkBrackets(char str[])
{
    Stack stack;
    init_stack(&stack);

    for (int i = 0; str[i] != '\0'; i++) { // Идем с первого символа строки до последнего, который в С \0

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&stack, str[i]); // Если встретилась открывающаяся скобка, то добавляем в стэк
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (StackEmptiness(&stack)) {
                return 0; // Обрабатываем случай, когда одна закрывающая и без открывающих
            }
            char lastElem = pop(&stack); // Достаем прошлый элемент стэка

            // проверяем соответствие скобок (они должны быть одного вида, если встретилась закрывающаяся)
            if ((lastElem == '(' && str[i] != ')') || (lastElem == '[' && str[i] != ']') || (lastElem == '{' && str[i] != '}')) {
                return 0;
                }
            // Если, например, встретились last == '{' и str[i] == '}', то все верно, идем дальше.
            // В стэк не добавляется новый элемент, а прошлый удаляется через pop
        }
    }
    return StackEmptiness(&stack); // если стек пуст, то все скобки проверены, и раз стэк не вернул 0, то строка сбалансирована
}

int main()
{
    char str[1000]; // Фиксированный размер массива

    printf("Введите строку: ");

    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    if (checkBrackets(str)) {
        printf("Сбалансирована\n");
    } else {
        printf("Не слабалансирована\n");
    }

    return 0;
}
