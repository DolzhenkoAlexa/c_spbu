#pragma once

struct ListOfWarriors {
    int position;
    struct ListOfWarriors* next;
};

// Функция создания циклического списка из n воинов
struct ListOfWarriors* createList(int n);

// Удаление война в списке
void deleteWarrior(struct ListOfWarriors** current);

int counter(int n, int m);
