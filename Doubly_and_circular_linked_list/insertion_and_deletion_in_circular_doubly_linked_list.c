#include <stdio.h>
#include <stdlib.h>

struct DCLLNode {
    int data;
    struct DCLLNode* prev;
    struct DCLLNode* next;
};

struct DCLLNode* createDCLLNode(int data) {
    struct DCLLNode* newNode = (struct DCLLNode*)malloc(sizeof(struct DCLLNode));
    newNode->data = data;
    return newNode;
}

struct DCLLNode* insertDCLL(struct DCLLNode* head, int data, int position) {
    struct DCLLNode* newNode = createDCLLNode(data);
    if (head == NULL) {
        if (position != 1) return NULL; 
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    if (position == 1) {
        struct DCLLNode* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        return newNode;
    }

    struct DCLLNode* current = head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
        if (current == head) {
            printf("Position out of bounds\n");
            free(newNode);
            return head;
        }
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    return head;
}

struct DCLLNode* deleteDCLL(struct DCLLNode* head, int key) {
    if (head == NULL) return NULL;
    
    struct DCLLNode* current = head;
    
    do {
        if (current->data == key) {
            if (current == head && current->next == head) { // Only one node
                free(current);
                return NULL;
            }
            
            struct DCLLNode* prev = current->prev;
            struct DCLLNode* next = current->next;
            
            prev->next = next;
            next->prev = prev;
            
            if (current == head) head = next; 
            
            free(current);
            return head;
        }
        current = current->next;
    } while (current != head);

    printf("Element %d not found for deletion\n", key);
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
    head = insertDCLL(head, 10, 1);
    head = insertDCLL(head, 30, 2);
    head = insertDCLL(head, 20, 2); 
    printf("After Insertion: ");
    displayList_DCLL(head); 

    head = deleteDCLL(head, 20);
    printf("After Deleting 20: ");
    displayList_DCLL(head);
    return 0;
}