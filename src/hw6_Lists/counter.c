#include <stdio.h>
#include <stdlib.h>
#include "counter.h"

struct ListOfWarriors* createList(int n)
{

    struct ListOfWarriors* first = malloc(sizeof(struct ListOfWarriors)); // Создаем циклический список
    first->position = 1;

    struct ListOfWarriors* current = first;
    for (int i = 2; i <= n; i++) {
        current->next = malloc(sizeof(struct ListOfWarriors));
        current = current->next;
        current->position = i;
    }
    current->next = first; // Замыкаем круг в циклическом списке

    return first;
}

void deleteWarrior(struct ListOfWarriors** current)
{
    struct ListOfWarriors* toDelete = (*current)->next;
    (*current)->next = toDelete->next;
    free(toDelete);
    *current = (*current)->next; // Переходим к следующему
}

int counter(int n, int m)
{
    if (n <= 0 || m <= 0) {
        printf("Нельзя вводить отрицательные m, n\n");
        return -1;
    }

    if (m == 1) {
        return n; // Возвращаем нужный номер
    }

    struct ListOfWarriors* current = createList(n);

    while (current->next != current) { //Пока не останется один воин (когда узел указывает сам на себя)
        // Находим воина под номером m-1
        for (int i = 1; i < m - 1; i++) {
            current = current->next;
        }

        deleteWarrior(&current); // Удаляем следующего воина от найденного (то есть под номером m)
    }

    int neededPosition = current->position;
    free(current);
    return neededPosition; // Возвращаем нужный номер
}
