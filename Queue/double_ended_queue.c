#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

void insertFront(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    deque[front] = data;
}

void insertRear(int data) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = data;
}

int deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return -1;
    }
    int data = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    return data;
}

int deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return -1;
    }
    int data = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
    return data;
}

void display() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    do {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    printf("Deleted from Front: %d\n", deleteFront());
    printf("Deleted from Rear: %d\n", deleteRear());
    display();
    return 0;
}
