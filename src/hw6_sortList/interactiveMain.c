#include <stdio.h>
#include "sortList.h"

int main(void)
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
            while (getchar() != '\n'); // очистка ввода
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
                    while (getchar() != '\n');
                    continue;
                }
                insertElement(list, inputElement);
                break;

            case 2:
                printf("Введите значение для удаления:");

                if (scanf("%d", &inputElement) != 1) {
                    printf("Ошибка: вводите только цифры\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (deleteElement(list, inputElement)) {
                    printf("Значение было удалено\n");
                } else {
                    printf("Элемент не найден\n");
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
