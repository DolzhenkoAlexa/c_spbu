#include <stdio.h>
#include <stdlib.h>

struct ListOfWarriors
{
    int position;
    struct ListOfWarriors* next;
};


int counter(int n, int m)
{
    if (n <= 0 || m <= 0) {
        printf("Нельзя вводить отрицательные m, n\n");
        return -1;
    }

    struct ListOfWarriors* first = malloc(sizeof(*first)); // Создаем циклический список
    first->position = 1;

    struct ListOfWarriors* current = first;
    for (int i = 2; i <= n; i++) {
        current->next = malloc(sizeof(*current));
        current = current->next;
        current->position = i;
    }
    current->next = first; // Замыкаем круг в циклическом списке

    current = first;
    while (current->next != current) { //Пока не останется один воин (когда узел указывает сам на себя)
        // Находим воина под номером m-1
        for (int i = 1; i < m - 1; i++) {
            current = current->next;
        }

        // Удаляем следующего воина от найденного (то есть под номером m)
        struct ListOfWarriors* deletedWarrior = current->next;
        current->next = deletedWarrior->next;
        current = current->next; // Переходим к следующему
        free(deletedWarrior);
    }

    int neededPosition = current->position;
    free(current);

    return neededPosition; // Возвращаем нужный номер
}

int main()
{
    int n, m;

    printf("Введите n и m: ");
    scanf("%d %d", &n, &m);

    int result = counter(n, m);
    printf("Нужная позиция: %d\n", result);

    return 0;
}