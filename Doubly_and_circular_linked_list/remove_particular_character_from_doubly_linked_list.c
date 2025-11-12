#include <stdio.h>
#include <stdlib.h>

struct CharDLLNode {
    char data;
    struct CharDLLNode* prev;
    struct CharDLLNode* next;
};

struct CharDLLNode* createCharDLLNode(char data) {
    struct CharDLLNode* newNode = (struct CharDLLNode*)malloc(sizeof(struct CharDLLNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct CharDLLNode* insertCharDLL(struct CharDLLNode* head, char data) {
    struct CharDLLNode* newNode = createCharDLLNode(data);
    if (head == NULL) return newNode;
    struct CharDLLNode* current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct CharDLLNode* removeChar(struct CharDLLNode* head, char key) {
    struct CharDLLNode* current = head;
    
    while (current != NULL) {
        if (current->data == key) {
            struct CharDLLNode* temp = current;
            
            if (current == head) {
                head = current->next;
                if (head != NULL) head->prev = NULL;
            } else {
                current->prev->next = current->next;
                if (current->next != NULL) current->next->prev = current->prev;
            }
            
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

void displayCharList(struct CharDLLNode* head) {
    struct CharDLLNode* current = head;
    while (current != NULL) {
        printf("%c <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct CharDLLNode* head = NULL;
    char str[] = "programming";
    for (int i = 0; str[i] != '\0'; i++) {
        head = insertCharDLL(head, str[i]);
    }

    printf("Original List: ");
    displayCharList(head);

    head = removeChar(head, 'g');
    printf("After removing 'g': ");
    displayCharList(head);
    
    return 0;
}