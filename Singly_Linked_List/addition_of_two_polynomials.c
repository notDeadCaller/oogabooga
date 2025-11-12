#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff;
    int power;
    struct PolyNode* next;
};

struct PolyNode* createPolyNode(int c, int p) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = c;
    newNode->power = p;
    newNode->next = NULL;
    return newNode;
}

struct PolyNode* insertPolyTerm(struct PolyNode* head, int c, int p) {
    struct PolyNode* newNode = createPolyNode(c, p);
    if (head == NULL) {
        return newNode;
    }
    struct PolyNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct PolyNode* addPolynomials(struct PolyNode* p1, struct PolyNode* p2) {
    struct PolyNode* resHead = NULL;
    struct PolyNode* resTail = NULL;
    
    while (p1 != NULL || p2 != NULL) {
        int newCoeff = 0;
        int newPower = 0;
        
        if (p1 == NULL) {
            newCoeff = p2->coeff;
            newPower = p2->power;
            p2 = p2->next;
        } else if (p2 == NULL) {
            newCoeff = p1->coeff;
            newPower = p1->power;
            p1 = p1->next;
        } else if (p1->power == p2->power) {
            newCoeff = p1->coeff + p2->coeff;
            newPower = p1->power;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->power > p2->power) {
            newCoeff = p1->coeff;
            newPower = p1->power;
            p1 = p1->next;
        } else {
            newCoeff = p2->coeff;
            newPower = p2->power;
            p2 = p2->next;
        }

        if (newCoeff != 0) {
            struct PolyNode* newNode = createPolyNode(newCoeff, newPower);
            if (resHead == NULL) {
                resHead = newNode;
                resTail = newNode;
            } else {
                resTail->next = newNode;
                resTail = newNode;
            }
        }
    }
    return resHead;
}

void displayPolynomial(struct PolyNode* head) {
    struct PolyNode* current = head;
    while (current != NULL) {
        printf("%+dx^%d ", current->coeff, current->power);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct PolyNode* poly1 = NULL;
    poly1 = insertPolyTerm(poly1, 5, 2);
    poly1 = insertPolyTerm(poly1, 4, 1);
    poly1 = insertPolyTerm(poly1, 2, 0);

    struct PolyNode* poly2 = NULL;
    poly2 = insertPolyTerm(poly2, -5, 1);
    poly2 = insertPolyTerm(poly2, 5, 0);
    poly2 = insertPolyTerm(poly2, 6, 3);
    
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    struct PolyNode* result = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(result);
    
    return 0;
}