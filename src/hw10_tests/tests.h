//
// Created by sasha on 19.11.2025.
//

#ifndef TESTS_H
#define TESTS_H

#include "sortListForTests.h"  // чтобы видеть List и базовые функции списка

// Проверка того, что сортировка списка соответствует expected
int checkList(struct List* list, int arr[], int n);

// Вставка в лист и изменение expected, в конце - сортировка массива
void insertElem(struct List* list, int value, int expected[], int* count);

// Удаление элемента из списка и из expected
void deleteElem(struct List* list, int value, int expected[], int* count);

// Запуск тестов
void runTests();

#endif // TESTS_H
