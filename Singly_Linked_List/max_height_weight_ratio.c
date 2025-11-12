#include <stdio.h>
#include <stdlib.h>

struct Student {
    int height;
    int weight;
    struct Student* next;
};

struct Student* createStudentNode(int h, int w) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->height = h;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

struct Student* insertStudent(struct Student* head, int h, int w) {
    struct Student* newNode = createStudentNode(h, w);
    if (head == NULL) {
        return newNode;
    }
    struct Student* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

double findMaxRatio(struct Student* head) {
    if (head == NULL) {
        return 0.0;
    }
    double maxRatio = -1.0;
    struct Student* current = head;
    while (current != NULL) {
        if (current->height > 0) {
            double currentRatio = (double)current->weight / current->height;
            if (currentRatio > maxRatio) {
                maxRatio = currentRatio;
            }
        }
        current = current->next;
    }
    return maxRatio;
}

int main() {
    struct Student* head = NULL;
    head = insertStudent(head, 170, 75);
    head = insertStudent(head, 160, 80);
    head = insertStudent(head, 180, 70);
    
    double maxRatio = findMaxRatio(head);
    printf("Highest weight/height ratio: %.4f\n", maxRatio);
    
    return 0;
}