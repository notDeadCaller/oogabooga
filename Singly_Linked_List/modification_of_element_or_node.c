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

void modifyNode(struct Node* head, int oldData, int newData) {
    struct Node* current = head;
    int found = 0;
    while (current != NULL) {
        if (current->data == oldData) {
            current->data = newData;
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Element %d not found for modification\n", oldData);
    }
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
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printf("Original List: ");
    displayList(head);
    modifyNode(head, 20, 25);
    printf("List after modification: ");
    displayList(head);
    return 0;
}