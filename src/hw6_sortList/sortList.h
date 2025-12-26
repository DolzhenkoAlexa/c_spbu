#pragma once

struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
    int size;
};

// Создание пустого списка
struct List* createEmptyList();

// Реализация команды 0 - выйти:
// Удаление всего списка для освобождения и выхода
void deleteList(struct List* list);

// Реализация команды 1 - добавить значениe в сортированный список:
void insertElement(struct List* list, int element);

// Реализация команды 2 – удалить значение из списка:
int deleteElement(struct List* list, int element);

// Реализация команды 3 – распечатать список:
void printList(struct List* list);

