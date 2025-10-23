//
// Created by sasha on 23.10.2025.
//

#include "sortingStation.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

// Проверяем является ли данный нам символ знаком операции (умножения/деления/сложения/вычитания)
int isOperator(char currElem) {
    return currElem == '+' || currElem == '-' || currElem == '*' || currElem == '/';
}

// Проверяем приоритет данного нам знака (по мат законам у деления/умножения он выше чем у сложения/вычитания)
int priority(char currElem) {
    if (currElem == '+' || currElem == '-') {
        return 1;
    }
    if (currElem == '*' || currElem == '/') {
        return 2;
    }
    return 0;
}


// Само преобразованиие Дейкстры
void toPostfix(char infix[], char postfix[]) {
    Stack stack;
    init_stack(&stack);
    int postfix_index = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char currElem = infix[i];

        // Пропускаем пробелы
        if (currElem == ' ') {
            continue;
        }

        // Если цифра - добавляем в массив postfix, так как числа идут первыми, а потом операции
        if (isdigit(currElem)) {
            postfix[postfix_index++] = currElem; // Добавляем число в следующий индекс массива
            postfix[postfix_index++] = ' '; // Делаем пробелы между символами, чтоб не слипалось
        }

        // Если открывающая скобка, то в стек
        else if (currElem == '(') {
            push(&stack, currElem);
        }

        // Закрывающая скобка завершает выражение в скобках.
        // Вынимаем из стека все операции пока не найдем открывающую скобку
        else if (currElem == ')') {
            while (!StackEmptiness(&stack)) {
                char operator = pop(&stack);
                if (operator == '(') {
                    break;
                }
                postfix[postfix_index++] = operator;
                postfix[postfix_index++] = ' ';
            }
        }
        // Если операция
        else if (isOperator(currElem)) {
            // Вынимаем операторы с более высоким или равным приоритетом, так как надо чтобы в выражениях, где важен порядок, они выполнялись быстрее
            while (!StackEmptiness(&stack)) {
                char lastOperator = stack.elements[stack.topIndex];
                if (lastOperator == '(') { // Останавливаем, если встречаем открывающую скобку
                    break;
                }
                if (priority(lastOperator) >= priority(currElem)) { // Сравниваем приоритетность операторов
                    // Оператор из стека имеет высший или равный приоритет - вынимаем его
                    pop(&stack);
                    postfix[postfix_index++] = lastOperator;
                    postfix[postfix_index++] = ' ';
                } else {
                    // Оператор из стека имеет низший - останаваливаем вынимание
                    break;
                }
            }
            // Кладем текущий оператор в стек
            push(&stack, currElem);
        }
    }

    // Вынимаем все оставшиеся символы операций из стека
    while (!StackEmptiness(&stack)) {
        char lastOperator = pop(&stack);
        postfix[postfix_index++] = lastOperator;
        postfix[postfix_index++] = ' ';
    }
}

int main() {
    char infix[500];
    char postfix[500];

    printf("Введите выражение со скобками, цифрами и операторами ");
    fgets(infix, sizeof(infix), stdin);


    infix[strlen(infix) - 1] = '\0';

    toPostfix(infix, postfix);

    printf("Инфиксная форма:  %s\n", infix);
    printf("Постфиксная форма: %s\n", postfix);

    return 0;
}