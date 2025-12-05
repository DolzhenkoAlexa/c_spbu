//
// Created by sasha on 05.12.2025.
//

#ifndef KR_PALINDROME_H
#define KR_PALINDROME_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createEmptyList(int data);

void insertElement(Node**, int data);

void printList(Node* head);

void freeList(Node* head);

int checkSimetric(Node* head);

#endif //KR_PALINDROME_H