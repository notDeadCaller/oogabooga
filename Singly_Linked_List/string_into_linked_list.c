#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CharNode {
    char data;
    struct CharNode* next;
};

struct CharNode* createCharNode(char data) {
    struct CharNode* newNode = (struct CharNode*)malloc(sizeof(struct CharNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct CharNode* stringToLinkedList(const char* str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }
    struct CharNode* head = NULL;
    struct CharNode* tail = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        struct CharNode* newNode = createCharNode(str[i]);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void displayCharList(struct CharNode* head) {
    struct CharNode* current = head;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    const char* myString = "Hello";
    struct CharNode* charListHead = stringToLinkedList(myString);
    displayCharList(charListHead);
    return 0;
}