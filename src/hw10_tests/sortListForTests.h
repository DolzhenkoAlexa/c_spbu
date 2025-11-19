//
// Created by sasha on 19.11.2025.
//

#ifndef SORTLISTFORTESTS_MAIN_H
#define SORTLISTFORTESTS_MAIN_H

// Cтруктура для узла списка
struct Node {
    int data; // данные узла
    struct Node* next; // указатель на следующий узел
};


// Структура для самого списка
struct List {
    struct Node* head; // указатель на начало списка
    int size; // размер списка
};

// Создание пустого списка
struct List* createEmptyList();

// Получение элемента по индексу
int getElement(struct List* list, int i);

// Реализация команды 0 - выйти:
// Удаление всего списка для освобождения и выхода
void deleteList(struct List* list);

// Реализация команды 1 - добавить значениe в сортированный список:
// Поиск позиции для вставки элемента в список
int findPosition(struct List* list, int element);

// Вставка элемента в список по заданному индексу
void insertElement(struct List* list, int i, int element);

// Реализация команды 2 – удалить значение из списка:
// Проверка наличия значения в списке
int checkElement(struct List* list, int element);

// Удаление элемента по индексу
void deleteElement(struct List* list, int i);

// Реализация команды 3 – распечатать список:
// распечатывание содержимое списка
void printList(struct List* list);

void runTests();


#endif //SORTLISTFORTESTS_MAIN_H