#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd_SCL(struct Node* last, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        last->next = last;
        return last;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
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
    last = insertAtEnd_SCL(last, 10);
    last = insertAtEnd_SCL(last, 20);
    last = insertAtEnd_SCL(last, 30);
    printf("Singly Circular List: ");
    displayList_SCL(last);
    return 0;
}