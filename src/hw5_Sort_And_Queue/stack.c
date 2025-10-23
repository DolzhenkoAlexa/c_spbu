//
// Created by sasha on 23.10.2025.
//

#include "stack.h"

// Создаем стэк, делая значение top равным -1 ("нет элементов")
void init_stack(Stack *stack) {
    stack->topIndex = -1;
}

// Добавляем элемент
void push(Stack *stack, char value) {
    stack->topIndex++; // Увеличиваем индекс на 1
    stack->elements[stack->topIndex] = value; // Добавляем сам элемент в массив
}

// Берем верхний элемент и удаляем его
char pop(Stack *stack) {
    if (StackEmptiness(stack)) {     // Проверяем не пуст ли стек
        return '\0';                 // Возвращаем '\0' если пуст (в таком виде, потому что нужно вернуть char)
    }
    char value = stack->elements[stack->topIndex];  // Сохраняем верхний элемент
    stack->topIndex--;               // Уменьшаем индекс
    return value;                    // Возвращаем сохраненный элемент
}

// Проверяем пуст ли стек (Чтоб не убрать "пустоту")
int StackEmptiness(Stack *stack) {
    if (stack->topIndex == -1) {
        return 1;  // 1 - стек пуст
    } else {
        return 0;  // 0 - стек не пуст
    }
}