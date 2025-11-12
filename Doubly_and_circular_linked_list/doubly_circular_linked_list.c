#include <stdio.h>
#include <stdlib.h>

struct DCLLNode {
    int data;
    struct DCLLNode* prev;
    struct DCLLNode* next;
};

struct DCLLNode* insertAtEnd_DCLL(struct DCLLNode* head, int data) {
    struct DCLLNode* newNode = (struct DCLLNode*)malloc(sizeof(struct DCLLNode));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    struct DCLLNode* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    return head;
}

void displayList_DCLL(struct DCLLNode* head) {
    if (head == NULL) return;
    struct DCLLNode* p = head;
    do {
        printf("%d <-> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(Head)\n");
}

int main() {
    struct DCLLNode* head = NULL;
    head = insertAtEnd_DCLL(head, 1);
    head = insertAtEnd_DCLL(head, 2);
    head = insertAtEnd_DCLL(head, 3);
    printf("Doubly Circular Linked List: ");
    displayList_DCLL(head);
    return 0;
}