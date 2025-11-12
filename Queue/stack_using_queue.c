#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
 q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->arr[++(q->rear)] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[(q->front)++];
}

void push(Queue* q, int value) {
    enqueue(q, value);
    int n = q->rear - q->front;
    while (n--) {
        enqueue(q, dequeue(q));
    }
}

int pop(Queue* q) {
    if (isEmpty(q)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return dequeue(q);
}
int main() {
    Queue q;
    initQueue(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);

    printf("Popped element: %d\n", pop(&q));
    printf("Popped element: %d\n", pop(&q));
    printf("Popped element: %d\n", pop(&q));

    return 0;
}