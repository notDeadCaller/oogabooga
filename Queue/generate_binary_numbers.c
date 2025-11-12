#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 100

// Using a linked list queue to handle strings (binary numbers)
struct Node {
    char* data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return;
    newNode->data = data;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

char* dequeue() {
    if (front == NULL) return NULL;
    struct Node* temp = front;
    char* data = temp->data;
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return data;
}

void generateBinary(int n) {
    if (n <= 0) return;
    
    char* first = (char*)malloc(2 * sizeof(char));
    strcpy(first, "1");
    enqueue(first);

    printf("Binary numbers from 1 to %d: ", n);
    for (int i = 1; i <= n; i++) {
        char* current = dequeue();
        printf("%s ", current);
        
        char* c1 = (char*)malloc((strlen(current) + 2) * sizeof(char));
        strcpy(c1, current);
        strcat(c1, "0");
        enqueue(c1);
        
        char* c2 = (char*)malloc((strlen(current) + 2) * sizeof(char));
        strcpy(c2, current);
        strcat(c2, "1");
        enqueue(c2);
        
        free(current);
    }
    printf("\n");
}

int main() {
    generateBinary(10);
    
    // Clean up remaining queue elements
    while (front != NULL) {
        free(dequeue());
    }
    return 0;
}
