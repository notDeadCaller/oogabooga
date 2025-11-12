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

struct DLLNode* insertDLL(struct DLLNode* head, int data, int position) {
    struct DLLNode* newNode = createDLLNode(data);
    if (position == 1) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        return newNode;
    }

    struct DLLNode* current = head;
    for (int i = 1; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) current->next->prev = newNode;
    current->next = newNode;
    return head;
}

struct DLLNode* deleteDLL(struct DLLNode* head, int position) {
    if (head == NULL) return NULL;

    struct DLLNode* temp = head;

    if (position == 1) {
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        return head;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return head;
    }

    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    
    free(temp);
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
    head = insertDLL(head, 10, 1);
    head = insertDLL(head, 30, 2);
    head = insertDLL(head, 20, 2); 
    printf("After Insertion: ");
    displayList_DLL(head); 

    head = deleteDLL(head, 2);
    printf("After Deletion at pos 2: ");
    displayList_DLL(head);
    return 0;
}