#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

// Queue implementation (same as Q1)
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = data;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    int data = queue[front++];
    if (front > rear) front = rear = -1;
    return data;
}

// Stack implementation (for reversal)
int stack[MAX_SIZE];
int top = -1;

void push_s(int data) {
    if (top >= MAX_SIZE - 1) return;
    stack[++top] = data;
}

int pop_s() {
    if (top < 0) return -1;
    return stack[top--];
}

void reverseQueue() {
    // 1. Dequeue all elements and push to stack
    while (front != -1) {
        push_s(dequeue());
    }
    
    // 2. Pop all elements from stack and enqueue back
    while (top >= 0) {
        enqueue(pop_s());
    }
}

void display_queue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("Original Queue: ");
    display_queue();
    
    reverseQueue();
    printf("Reversed Queue: ");
    display_queue();
    return 0;
}
