#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

// A basic array implementation where higher value means higher priority (Max Heap concept)
int pq[MAX_SIZE];
int size = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain Max Heap property after insertion (bubble up)
void maxHeapifyUp(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (pq[index] > pq[parent]) {
        swap(&pq[index], &pq[parent]);
        maxHeapifyUp(parent);
    }
}

// Function to maintain Max Heap property after extraction (bubble down)
void maxHeapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && pq[left] > pq[largest]) {
        largest = left;
    }
    if (right < size && pq[right] > pq[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&pq[index], &pq[largest]);
        maxHeapifyDown(largest);
    }
}

void insert(int data) {
    if (size >= MAX_SIZE) {
        printf("Priority Queue Overflow\n");
        return;
    }
    pq[size] = data;
    maxHeapifyUp(size);
    size++;
}

int extractMax() {
    if (size <= 0) {
        printf("Priority Queue Underflow\n");
        return -1;
    }
    int max = pq[0];
    pq[0] = pq[size - 1];
    size--;
    maxHeapifyDown(0);
    return max;
}

void display() {
    if (size == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }
    printf("Priority Queue elements (Heap Order): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(50);
    insert(20);
    insert(80); // Highest priority
    display();
    printf("Extracted Max (Highest Priority): %d\n", extractMax());
    display();
    return 0;
}
