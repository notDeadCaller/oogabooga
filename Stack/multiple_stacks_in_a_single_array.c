#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 100
#define NUM_STACKS 3

int arr[ARRAY_SIZE];
int top[NUM_STACKS];
int boundary[NUM_STACKS + 1];

void initializeStacks() {
    int stackSize = ARRAY_SIZE / NUM_STACKS;
    boundary[0] = -1;
    for (int i = 0; i < NUM_STACKS; i++) {
        top[i] = boundary[i];
        boundary[i + 1] = boundary[i] + stackSize;
    }
    boundary[NUM_STACKS] = ARRAY_SIZE - 1;
}

void push(int stackNum, int data) {
    if (stackNum < 0 || stackNum >= NUM_STACKS) {
        printf("Invalid stack number\n");
        return;
    }
    if (top[stackNum] >= boundary[stackNum + 1]) {
        printf("Stack %d Overflow\n", stackNum);
        return;
    }
    top[stackNum]++;
    arr[top[stackNum]] = data;
}

int pop(int stackNum) {
    if (stackNum < 0 || stackNum >= NUM_STACKS) {
        printf("Invalid stack number\n");
        return -1;
    }
    if (top[stackNum] <= boundary[stackNum]) {
        printf("Stack %d Underflow\n", stackNum);
        return -1;
    }
    return arr[top[stackNum]--];
}

void display(int stackNum) {
    if (stackNum < 0 || stackNum >= NUM_STACKS) {
        printf("Invalid stack number\n");
        return;
    }
    if (top[stackNum] <= boundary[stackNum]) {
        printf("Stack %d is Empty\n", stackNum);
        return;
    }
    printf("Stack %d elements: ", stackNum);
    for (int i = top[stackNum]; i > boundary[stackNum]; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    initializeStacks();
    push(0, 10);
    push(0, 20);
    push(1, 100);
    push(2, 500);
    push(2, 600);
    
    display(0);
    display(1);
    display(2);
    
    printf("Popped from stack 2: %d\n", pop(2));
    display(2);
    return 0;
}
