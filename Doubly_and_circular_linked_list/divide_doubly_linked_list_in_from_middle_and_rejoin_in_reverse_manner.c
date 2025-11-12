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
    if (head == NULL) return newNode;
    struct DLLNode* current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct DLLNode* reverseDLL_Segment(struct DLLNode* head) {
    struct DLLNode* temp = NULL;
    struct DLLNode* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }
    if (temp != NULL) head = temp->prev;
    return head;
}

struct DLLNode* divideAndRejoin(struct DLLNode* head) {
    if (head == NULL || head->next == NULL) return head;

    struct DLLNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Split the list
    struct DLLNode* head1 = head;
    struct DLLNode* head2 = slow->next;
    slow->next = NULL;
    head2->prev = NULL;
    
    // Reverse segments
    head1 = reverseDLL_Segment(head1);
    head2 = reverseDLL_Segment(head2);
    
    // Rejoin
    struct DLLNode* current = head1;
    while (current->next != NULL) current = current->next;
    current->next = head2;
    if (head2 != NULL) head2->prev = current;
    
    return head1;
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
    head = insertAtEnd_DLL(head, 11);
    head = insertAtEnd_DLL(head, 22);
    head = insertAtEnd_DLL(head, 33);
    head = insertAtEnd_DLL(head, 44);
    head = insertAtEnd_DLL(head, 55);
    head = insertAtEnd_DLL(head, 66);

    printf("Original List: ");
    displayList_DLL(head);
    
    head = divideAndRejoin(head);
    printf("Rejoined List: ");
    displayList_DLL(head);
    
    return 0;
}