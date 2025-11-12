#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

// Use two stacks (s1 and s2) to implement queue
int s1[MAX_SIZE];
int t1 = -1;
int s2[MAX_SIZE];
int t2 = -1;

void push(int* s, int* t, int data) {
    if (*t >= MAX_SIZE - 1) return;
    s[++(*t)] = data;
}

int pop(int* s, int* t) {
    if (*t < 0) return -1;
    return s[(*t)--];
}

void enqueue(int data) {
    if (t1 >= MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    
    while (t1 >= 0) {
        push(s2, &t2, pop(s1, &t1));
    }
    
    push(s1, &t1, data);
    
    while (t2 >= 0) {
        push(s1, &t1, pop(s2, &t2));
    }
}

int dequeue() {
    if (t1 < 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    return pop(s1, &t1);
}

void display_queue() {
    if (t1 < 0) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements (Front to Rear): ");
    for (int i = 0; i <= t1; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display_queue();
    printf("Dequeued: %d\n", dequeue());
    enqueue(40);
    display_queue();
    return 0;
}
