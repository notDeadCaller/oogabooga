#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtStart_SCL(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    return last;
}

struct Node* deleteNode_SCL(struct Node* last, int key) {
    if (last == NULL) return NULL;
    struct Node *current = last->next, *prev = last;

    do {
        if (current->data == key) {
            if (current == last->next) { // Deleting head
                if (current == last) { // Only one node
                    free(current);
                    return NULL;
                }
                last->next = current->next;
                free(current);
                return last;
            } else if (current == last) { // Deleting last
                prev->next = last->next;
                free(current);
                return prev;
            } else { // Deleting middle node
                prev->next = current->next;
                free(current);
                return last;
            }
        }
        prev = current;
        current = current->next;
    } while (current != last->next);

    return last;
}

void displayList_SCL(struct Node* last) {
    if (last == NULL) return;
    struct Node* p = last->next;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("(Head)\n");
}

int main() {
    struct Node* last = NULL;
    last = insertAtStart_SCL(last, 20);
    last = insertAtStart(last, 10);
    last = insertAtStart(last, 5);
    printf("After Insertion: ");
    displayList_SCL(last);
    
    last = deleteNode_SCL(last, 10);
    printf("After Deleting 10: ");
    displayList_SCL(last);

    last = deleteNode_SCL(last, 5);
    printf("After Deleting 5: ");
    displayList_SCL(last);
    return 0;
}