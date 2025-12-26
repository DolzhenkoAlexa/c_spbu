#pragma once

#include "../sortList.h"

// Создание списка из массива
struct List* createListFromArr(int arr[], int n);

// Проверка того, что сортировка списка соответствует expected
int checkList(struct List* list, int arr[], int n);

// Тест 1: Вставка первого элемента
int testInsertFirstElement();

// Тест 2: Вставка нескольких элементов
int testInsertMany();

// Тест 3: Вставка повторяющихся элементов
int testInsertDuplicates();

// Тест 4: Удаление элементов в начале, середине и конце
int testDeleteLastElement();

// Тест 5: Удаление нескольких элементов (намеренно в начале, середине и конце)
int testDeleteMultiple();

// Тест 6: Удаление дубликатов элементов
int testDeleteDuplicates();

// Тест 7: Удаление несуществующего элемента
int testDeleteNonexistent();

// Определение "пройдено" или "не пройдено"
void printTestResult(char* testName, int result);

// Запуск тестов
void runTests();
