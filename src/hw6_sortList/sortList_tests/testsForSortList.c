#include <stdio.h>
#include "testsForSortList.h"

// Создание списка из массива чтобы не было 20-ти insert
struct List* createListFromArr(int arr[], int n) {
    struct List* list = createEmptyList();
    for (int i = 0; i < n; i++) {
        insertElement(list, arr[i]);
    }
    return list;
}

// Проверка того, что сортировка списка соответствует expected
int checkList(struct List* list, int arr[], int n) {
    if (list->size != n) {
        return 0;
    }
    struct Node* curr = list->head;
    for (int i = 0; i < n; i++) {
        if (!curr || curr->data != arr[i]) {
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}

// Тесты
int testInsertFirstElement() {
    int expected[1] = {10};
    struct List* lst = createEmptyList();
    insertElement(lst, 10);

    int res = checkList(lst, expected, 1);
    deleteList(lst);
    return res;
}

int testInsertMany() {
    int initial[] = {1, 3, 7819};
    int expected[6] = {-1, 0, 1, 3, 5, 7819};
    struct List* lst = createListFromArr(initial, 3);

    insertElement(lst, -1);
    insertElement(lst, 0);
    insertElement(lst, 5);

    int res = checkList(lst, expected, 6);
    deleteList(lst);
    return res;
}

int testInsertDuplicates() {
    int initial[] = {4, 2, 666};
    int expected[6] = {-5, -5, 2, 2, 4, 666};
    struct List* lst = createListFromArr(initial, 3);

    insertElement(lst, -5);
    insertElement(lst, -5);
    insertElement(lst, 2);

    int res = checkList(lst, expected, 6);
    deleteList(lst);
    return res;
}

int testDeleteLastElement() {
    int initial[] = {52};
    int expected[1] = {};
    struct List* lst = createListFromArr(initial, 1);
    deleteElement(lst, 52);

    int res = checkList(lst, expected, 0);
    deleteList(lst);
    return res;
}

int testDeleteMultiple() {
    int initial[] = {-100, 0, 3, 5, 7, 999};
    int expected[3] = {0, 3, 5};
    struct List* lst = createListFromArr(initial, 6);

    deleteElement(lst, -100); // начало
    deleteElement(lst, 7);    // середина
    deleteElement(lst, 999);  // конец

    int res = checkList(lst, expected, 3);
    deleteList(lst);
    return res;
}

int testDeleteDuplicates() {
    int initial[] = {-1, 3, 0, 3, 5, 0, -1, 3, 3};
    int expected[5] = {-1, -1, 3, 3, 5};
    struct List* lst = createListFromArr(initial, 9);

    deleteElement(lst, 3);
    deleteElement(lst, 3);
    deleteElement(lst, 0);
    deleteElement(lst, 0);

    int res = checkList(lst, expected, 5);
    deleteList(lst);
    return res;
}

int testDeleteNonexistent() {
    int initial[] = {1, 2, 3};
    int expected[1] = {};
    struct List* lst = createListFromArr(initial, 3);

    deleteElement(lst, 1);
    deleteElement(lst, 2);
    deleteElement(lst, 3);
    deleteElement(lst, 10000);

    int res = checkList(lst, expected, 0);
    deleteList(lst);
    return res;
}

// Вывод результатов и логика определения пройденности
void printTestResult(char* testName, int result) {
    printf("%s: %s\n", testName, result ? "пройден!" : "НЕ пройден");
}

void runTests() {
    printTestResult("Тест 1: Вставка первого элемента", testInsertFirstElement());
    printTestResult("Тест 2: Вставка нескольких элементов", testInsertMany());
    printTestResult("Тест 3: Вставка повторяющихся элементов", testInsertDuplicates());
    printTestResult("Тест 4: Удаление единственного элемента", testDeleteLastElement());
    printTestResult("Тест 5: Удаление элементов в начале, середине, конце", testDeleteMultiple());
    printTestResult("Тест 6: Удаление дубликатов элементов", testDeleteDuplicates());
    printTestResult("Тест 7: Удаление несуществующего элемента", testDeleteNonexistent());

    printf("Конец тестов!\n");
}
