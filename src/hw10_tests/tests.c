//
// Created by sasha on 19.11.2025.
//

#include "sortListForTests.h"
#include "tests.h"
#include <stdio.h>

// Cортировка пузырьком для проверки отсортированности
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Проверка того, что сортировка списка соответствует expected
int checkList(struct List* list, int arr[], int n)
{
    if (list->size != n) {
        return 0;
    } else {
        for (int i = 0; i < n; i++) {
            if (getElement(list, i) != arr[i]) {
                return 0;
            }
        }
    }
    return 1;
}

// Вставка в лист и изменение expected, в конце - сортировка массива
void insertElem(struct List* list, int value, int expected[], int* count)
{
    insertElement(list, findPosition(list, value), value);
    expected[*count] = value;
    (*count)++;
    bubbleSort(expected, *count);
}

// Удаление элемента из списка и из expected
void deleteElem(struct List* list, int value, int expected[], int* count)
{
    int pos = checkElement(list, value);
    if (pos != -1) {
        deleteElement(list, pos);
    }
    int found = -1;
    for (int i = 0; i < *count; i++) {
        if (expected[i] == value) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        for (int i = found; i < *count - 1; i++) {
            expected[i] = expected[i + 1];
        }
        (*count)--;
    }
}

// Запуск тестов
void runTests()
{
    printf("Тесты:\n");
    struct List* list = createEmptyList();
    int expected[30];
    int count = 0;

    // Тест на добавление первого элемента
    printf("Тест 1: Вставка первого элемента. ");
    insertElem(list, 0, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на удаление единственного элемента в списке
    printf("Тест 2: Удаление единственного элемента. ");
    deleteElem(list, 0, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на удаление несуществующего элемента в списке
    printf("Тест 3: Удаление несуществующего элемента. ");
    deleteElem(list, 123, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на добавление нескольких элементов (отрицательные, положительные, 0)
    printf("Тест 4: Вставка нескольких элементов. ");
    int values[] = {0, -1, 20, 5, 52, 100, -5, -100};
    for (int i = 0; i < 8; i++) {
        insertElem(list, values[i], expected, &count);
    }
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на вставку в самое начало (малое число)
    printf("Тест 5: Вставка в начало. ");
    insertElem(list, -1000, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на вставку в самый конец (большое число)
    printf("Тест 6: Вставка в конец. ");
    insertElem(list, 1000, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на добавление повторок
    printf("Тест 7: Вставка повторяющихся элементов. ");
    int duplicates[] = {-5, 100, 100};
    for (int i = 0; i < 3; i++) {
        insertElem(list, duplicates[i], expected, &count);
    }
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на удаление элемента в начале
    printf("Тест 8: Удаление элемента в начале. ");
    deleteElem(list, -1000, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на удаление элемента в конце
    printf("Тест 9: Удаление элемента в конце\n");
    deleteElem(list, 1000, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на удаление элемента
    printf("Тест 10: Удаление элемента в середине\n");
    deleteElem(list, 0, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на удаление повторок
    printf("Тест 11: Удаление повторяющихся элементов\n");
    deleteElem(list, 100, expected, &count);
    deleteElem(list, -5, expected, &count);
    if (checkList(list, expected, count)) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    // Тест на очистку списка
    printf("Тест 12: Удаление всех элементов списка и очистка памяти\n");
    deleteList(list);
    list = NULL;
    count = 0;
    if (list == NULL && count == 0) {
        printf("Результат: пройден!\n");
    } else {
        printf("Результат: НЕ пройден\n");
    }

    printf("Конец тестов!\n");
}
