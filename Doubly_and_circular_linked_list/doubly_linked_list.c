#include <stdio.h>
#include <stdlib.h>

struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

struct DLLNode* createDLLNode(int data) {
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct DLLNode* insertAtEnd_DLL(struct DLLNode* head, int data) {
    struct DLLNode* newNode = createDLLNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct DLLNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

void displayList_DLL(struct DLLNode* head) {
    struct DLLNode* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct DLLNode* head = NULL;
    head = insertAtEnd_DLL(head, 100);
    head = insertAtEnd_DLL(head, 200);
    head = insertAtEnd_DLL(head, 300);
    printf("Doubly Linked List: ");
    displayList_DLL(head);
    return 0;
}