#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* leftShift(struct Node* head, int k) {
    if (head == NULL || k == 0) {
        return head;
    }
    struct Node* current = head;
    struct Node* newHead = NULL;
    struct Node* newTail = head;
    int count = 1;
    while (current->next != NULL) {
        current = current->next;
        count++;
    }
    current->next = head;
    int shift = k % count;
    if (shift == 0) {
        current->next = NULL;
        return head;
    }
    for (int i = 0; i < shift - 1; i++) {
        newTail = newTail->next;
    }
    newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;
    int k = 3;
    head = insertAtEnd(head, 22);
    head = insertAtEnd(head, 44);
    head = insertAtEnd(head, 77);
    head = insertAtEnd(head, 88);
    head = insertAtEnd(head, 99);
    printf("Original List: ");
    displayList(head);
    head = leftShift(head, k);
    printf("Shifted by %d: ", k);
    displayList(head);
    return 0;
}