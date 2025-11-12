#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 100
#define NUM_QUEUES 3

int arr[ARRAY_SIZE];
int front[NUM_QUEUES];
int rear[NUM_QUEUES];
int boundary[NUM_QUEUES + 1];

void initializeQueues() {
    int queueSize = ARRAY_SIZE / NUM_QUEUES;
    boundary[0] = -1;
    for (int i = 0; i < NUM_QUEUES; i++) {
        front[i] = rear[i] = boundary[i];
        boundary[i + 1] = boundary[i] + queueSize;
    }
    boundary[NUM_QUEUES] = ARRAY_SIZE - 1;
}

void enqueue(int queueNum, int data) {
    if (queueNum < 0 || queueNum >= NUM_QUEUES) return;
    
    if (rear[queueNum] == boundary[queueNum + 1]) {
        printf("Queue %d Overflow\n", queueNum);
        return;
    }
    rear[queueNum]++;
    arr[rear[queueNum]] = data;
    if (front[queueNum] == boundary[queueNum]) {
        front[queueNum]++;
    }
}

int dequeue(int queueNum) {
    if (queueNum < 0 || queueNum >= NUM_QUEUES) return -1;

    if (front[queueNum] > rear[queueNum] || front[queueNum] == boundary[queueNum]) {
        printf("Queue %d Underflow\n", queueNum);
        return -1;
    }
    int data = arr[front[queueNum]];
    front[queueNum]++;
    return data;
}

void display(int queueNum) {
    if (queueNum < 0 || queueNum >= NUM_QUEUES) return;
    
    if (front[queueNum] > rear[queueNum] || front[queueNum] == boundary[queueNum]) {
        printf("Queue %d is Empty\n", queueNum);
        return;
    }
    printf("Queue %d elements: ", queueNum);
    for (int i = front[queueNum]; i <= rear[queueNum]; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    initializeQueues();
    enqueue(0, 10);
    enqueue(0, 20);
    enqueue(1, 100);
    enqueue(2, 500);
    enqueue(2, 600);
    
    display(0);
    display(1);
    display(2);
    
    printf("Dequeued from queue 2: %d\n", dequeue(2));
    display(2);
    return 0;
}
