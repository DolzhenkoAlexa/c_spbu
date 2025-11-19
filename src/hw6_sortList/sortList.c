//
// Created by sasha on 19.11.2025.
//
#include <stdio.h>
#include "sortList.h"
#include <stdlib.h>

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

// Получение элемента по индексу
int getElement(struct List* list, int i)
{
    // Проверка корректности индекса
    if (i < 0 || i >= list->size) {
        printf("Некорректный индекс: он не может быть < 0 или больше размера списка\n");
        return -1;
    }

    struct Node* currNode = list->head;
    while (i--) {
        currNode = currNode->next;
    }
    return currNode->data;
}

// Реализация команды 0 - выйти:
// Удаление всего списка для освобождения и выхода
void deleteList(struct List* list)
{
    struct Node* currNode = list->head;
    // Удаление узлов
    while (currNode) {
        struct Node* tempNode = currNode;
        currNode = currNode->next;
        free(tempNode);
    }
    // Освобождение памяти
    free(list);
}

// Реализация команды 1 - добавить значение в сортированный список:
// Поиск позиции для вставки элемента в список
int findPosition(struct List* list, int element)
{
    if (list->size == 0)
        return 0;

    struct Node* currNode = list->head;
    int position = 0;

    // Ищем первую позицию, где след элемент больше нового значения
    // Так как список отсортирован, то прошлый будет или больше или равен вставляемому
    while (currNode && currNode->data < element) {
        currNode = currNode->next;
        position++;
    }
    return position;
}

// Вставка элемента в список по заданному индексу
void insertElement(struct List* list, int i, int element)
{
    // Проверка корректности индекса
    if (i < 0 || i > list->size) {
        printf("Некорректный индекс: он не может быть < 0 или больше размера списка\n");
        return;
    }

    // Создание нового узла
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Ошибка выделения памяти для саздания нового узла\n");
        return;
    }
    newNode->data = element;
    // Вставка
    if (i == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        // Поиск позиции для вставки
        struct Node* currNode = list->head;
        int pos = 1;
        while (pos < i) {
            currNode = currNode->next;
            pos++;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
    list->size++;
}

// Реализация команды 2 – удалить значение из списка:
// Проверка наличия значения в списке
int checkElement(struct List* list, int element)
{
    struct Node* currNode = list->head;
    int position = 0;

    while (currNode) {
        if (currNode->data == element) {
            return position;
        }
        currNode = currNode->next;
        position++;
    }
    return -1;
}

// Удаление элемента по индексу
void deleteElement(struct List* list, int i)
{
    // проверка корректности индекса
    if (i < 0 || i >= list->size) {
        printf("Некорректный индекс: он не может быть < 0 или больше размера списка\n");
        return;
    }
    struct Node* nodeForDeletion;
    // Удаление из начала списка
    if (i == 0) {
        nodeForDeletion = list->head;
        list->head = list->head->next;
    } else {
        // Поиск узла перед удаляемым
        struct Node* currNode = list->head;
        int pos = 1;
        while (pos < i) {
            currNode = currNode->next;
            pos++;
        }
        nodeForDeletion = currNode->next;
        currNode->next = nodeForDeletion->next;
    }
    // Освобождение памяти
    free(nodeForDeletion);
    list->size--;
}

// Реализация команды 3 – распечатать список:
// Печать содержимого списка
void printList(struct List* list)
{
    if (list->size == 0) {
        printf("Список пустой\n");
        return;
    }

    struct Node* currNode = list->head;
    printf("Содержание списка:\n");
    printf("[");
    while (currNode) {
        printf("%d", currNode->data);
        if (currNode->next) printf(", ");
        currNode = currNode->next;
    }
    printf("]\n");
}


// Функция main для реализации выбора команд 0-3 пользователем
int main()
{
    struct List* list = createEmptyList();
    int command, inputElement;

    while (1) {
        printf("Команды:\n");
        printf("0 - Выйти\n");
        printf("1 - Добавить значение в сортированный список\n");
        printf("2 - Удалить значение из списка\n");
        printf("3 - Распечатать список\n");
        printf("Выберите команду (0,1,2,3): ");


        if (scanf("%d", &command) != 1) {
            printf("Ошибка: вводите только цифры\n");
            int ch;
            while ((ch = getchar()) != '\n');

            continue;
        }

        switch (command) {
            case 0:
                printf("Совершён выход\n");
                deleteList(list);
                return 0;

            case 1:
                printf("Введите значение для добавления: ");

                if (scanf("%d", &inputElement) != 1) {
                    printf("Ошибка: вводите только цифры\n");

                    int ch;
                    while ((ch = getchar()) != '\n');

                    continue;
                }

                int position1 = findPosition(list, inputElement);
                insertElement(list, position1, inputElement);
                printf("Значение было добавлено на позицию %d\n", position1);
                break;

            case 2:
                printf("Введите значение для удаления:");

                if (scanf("%d", &inputElement) != 1) {
                    printf("Ошибка: вводите только цифры\n");

                    int ch;
                    while ((ch = getchar()) != '\n');

                    continue;
                }

                int position2 = checkElement(list, inputElement);
                if (position2 != -1) {
                    deleteElement(list, position2);
                    printf("Значение было удалено с позиции %d\n", position2);
                } else {
                    printf("Значение не найдено\n");
                }
                break;

            case 3:
                printList(list);
                break;

            default:
                printf("Введена неподдерживаемая команда: можно только 0,1,2,3\n");
        }
    }
}