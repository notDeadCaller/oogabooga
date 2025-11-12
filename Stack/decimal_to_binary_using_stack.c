#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 32

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top >= MAX_SIZE - 1) return;
    stack[++top] = data;
}

int pop() {
    if (top < 0) return -1;
    return stack[top--];
}

void decimalToBinary(int decimal) {
    int originalDecimal = decimal;
    if (decimal == 0) {
        printf("Binary equivalent of 0 is 0\n");
        return;
    }

    while (decimal > 0) {
        push(decimal % 2);
        decimal = decimal / 2;
    }
    
    printf("Binary equivalent of %d is: ", originalDecimal);
    while (top >= 0) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int num = 45;
    decimalToBinary(num);
    num = 13;
    decimalToBinary(num);
    return 0;
}
