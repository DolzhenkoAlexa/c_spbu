//
// Created by sasha on 05.12.2025.
//

#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>

//Проверить список на симметричность.
//С клавиатуры вводятся натуральные числа, построить по ним список и определить, симметричен ли он.
//Например, список из 10 20 30 20 10 симметричен, 10 20 30 40 20 10 — нет.
//Требуется использование настоящего списка на указателях, считать всё в массив не пойдёт.

Node* createList(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (!newNode) {
        printf("Error: Memory. Not able to create a list");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertElement(Node** head, int data) {
    Node* newNode = createList(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;

    }
    current->next = newNode;
}

void printList(Node* head) {
    printf("Printing the List: \n");
    printf("[");
    Node *current = head;

    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("]\n");
}

// Проверяет симметричность, если 0 - нет симметрии, если 1 - есть
int checkSimetric(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1;
        // Считаем, что пустой список или из 1 элемента симметричен
        // (ничто = ничто)
    }

    Node* end = head; // Указатель, который двигается по 2 узла, дойдет до конца
    Node* middle = head; // Когда end дойдет до конца этот должен быть на середине (наверное..)

    if (end != NULL && end->next != NULL) {
        middle = middle->next;
        end = end->next->next;
    }

    Node* prev = NULL;
    Node* next = NULL;
    Node* current = middle;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    Node* firstPart = head;
    Node* secondPart = prev;

    while (firstPart != NULL && secondPart != NULL) {
        if (firstPart->data != secondPart->data) {
            return 0;
            break;
        }

        firstPart = firstPart->next;
        secondPart = secondPart->next;
    }

    return 1;
}

void freeList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void testEmptyList() {
    Node* list = NULL;
    int result = checkSimetric(list);
    if (result == 1) {
        printf("Palindrome. Test1 passed\n");
    } else {
        printf("No palindrome. Test1 is not passed\n");
    }
    freeList(list);
}

void testSingleElement() {
    Node* list = NULL;
    insertElement(&list, 1);
    int result = checkSimetric(list);
    if (result == 1) {
        printf("Palindrome. Test2 passed\n");
    } else {
        printf("No palindrome. Test2 is not passed\n");
    }
    freeList(list);
}

void testNotPalindrome() {
    Node* list = NULL;
    insertElement(&list, 1);
    insertElement(&list, 2);
    insertElement(&list, 2);
    int result = checkSimetric(list);
    if (result == 0) {
        printf("Not palindrome. Test3 passed\n");
    } else {
        printf("Palindrome. Test3 is not passed\n");
    }
    freeList(list);
}

void testPalindrome() {
    Node* list = NULL;
    insertElement(&list, 1);
    insertElement(&list, 2);
    insertElement(&list, 2);
    insertElement(&list, 1);
    int result = checkSimetric(list);
    if (result == 1) {
        printf("Palindrome. Test4 passed\n");
    } else {
        printf("No palindrome. Test4 is not passed\n");
    }
    freeList(list);
}

int main() {
    Node* head = NULL;

    printf("Tests:\n");
    testEmptyList();
    testSingleElement();
    testNotPalindrome();
    testPalindrome();
    
    int element;
    printf("Enter numbers, for exiting enter negative number or 0 \n");

    while (1) {
        scanf("%d", &element);
        if (element <= 0) {
            printf("Exiting... \n");
            break;
        }
        insertElement(&head, element);
    }
    printList(head);
    int result = checkSimetric(head);
    if (result == 1) {
        printf("Palindrome\n");
    } else {
        printf("No palindrome\n");
    }

    freeList(head);

    return 0;
}






