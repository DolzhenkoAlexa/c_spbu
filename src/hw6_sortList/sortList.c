#include <stdio.h>
#include <stdlib.h>
#include "sortList.h"

// Создание пустого списка
struct List* createEmptyList()
{
    struct List* list = malloc(sizeof(struct List));
    if (!list) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Удаление всего списка
void deleteList(struct List* list)
{
    struct Node* curr = list->head;
    while (curr) {
        struct Node* tempNode = curr;
        curr = curr->next;
        free(tempNode);
    }
    
    free(list);
}

// Вставка элемента
void insertElement(struct List* list, int element)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Ошибка выделения памяти\n");
        return;
    }
    
    newNode->data = element;
    newNode->next = NULL;

    if (!list->head || list->head->data >= element) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        return;
    }

    // Поиск места
    struct Node* curr = list->head;
    while (curr->next && curr->next->data < element) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    list->size++;
}

// Удаление элемента
int deleteElement(struct List* list, int element)
{
    if (!list->head) {
        return 0;
    }

    if (list->head->data == element) {
        struct Node* tempNode = list->head;
        list->head = list->head->next;
        free(tempNode);
        list->size--;
        return 1;
    }

    // Поиск элемента
    struct Node* curr = list->head;
    while (curr->next && curr->next->data != element) {
        curr = curr->next;
    }

    if (!curr->next) {
        return 0; // не найденн
    }

    struct Node* tempNode = curr->next;
    curr->next = tempNode->next;
    free(tempNode);
    list->size--;
    return 1;
}

// Печать списка
void printList(struct List* list)
{
    if (!list->head) {
        printf("Список пуст\n");
        return;
    }

    struct Node* curr = list->head;
    printf("[");
    while (curr) {
        printf("%d", curr->data);
        if (curr->next) printf(", ");
        curr = curr->next;
    }
    printf("]\n");
}

