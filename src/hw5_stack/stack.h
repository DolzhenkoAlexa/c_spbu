// Этот модуль предоставляет функции для работы со стеком для Продвинутый баланс скобок и Сортировочная станция:
#pragma once
#define STACK_SIZE 512

// Структура для стека
typedef struct {
    char elements[STACK_SIZE];  // массив для хранения
    int topIndex;                // индекс верхнего элемента
} Stack;

// Создание стека
void init_stack(Stack *stack);

// Добавление элемента в стек
void push(Stack *stack, char value);

// Удаление элемента из стека с проверкой на пустоту
// Вернет значение элемента, если есть что удалять, и 0 если нет
char pop(Stack *stack);

// Проверка стэка на пустоту
// Вернет 1 если стек пуст, 0 если нет
int stackEmptiness(Stack *stack);
