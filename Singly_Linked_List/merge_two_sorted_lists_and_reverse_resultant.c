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

struct Node* mergeSortedLists(struct Node* h1, struct Node* h2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (h1 != NULL && h2 != NULL) {
        if (h1->data <= h2->data) {
            tail->next = h1;
            h1 = h1->next;
        } else {
            tail->next = h2;
            h2 = h2->next;
        }
        tail = tail->next;
    }
    if (h1 != NULL) {
        tail->next = h1;
    } else if (h2 != NULL) {
        tail->next = h2;
    }
    return dummy.next;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    head1 = createNode(5);
    head1->next = createNode(15);
    head1->next->next = createNode(25);

    struct Node* head2 = NULL;
    head2 = createNode(10);
    head2->next = createNode(20);
    head2->next->next = createNode(30);

    struct Node* mergedHead = mergeSortedLists(head1, head2);
    printf("Merged List: ");
    displayList(mergedHead);
    
    struct Node* reversedHead = reverseList(mergedHead);
    printf("Reversed Merged List: ");
    displayList(reversedHead);
    
    return 0;
}