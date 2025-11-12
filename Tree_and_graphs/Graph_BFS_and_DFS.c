#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* graph[MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void enqueue(int item) {
    if (rear == MAX_VERTICES - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(int startVertex) {
    for(int i = 0; i < MAX_VERTICES; i++) visited[i] = 0;
    front = rear = -1; 
    
    enqueue(startVertex);
    visited[startVertex] = 1;
    printf("BFS Traversal: ");

    while (front != -1 && front <= rear) {
        int current = dequeue();
        printf("%d ", current);
        
        struct Node* temp = graph[current];
        while (temp) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    struct Node* temp = graph[vertex];
    while (temp) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    for(int i = 0; i < MAX_VERTICES; i++) graph[i] = NULL;
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);
    
    BFS(0);

    for(int i = 0; i < MAX_VERTICES; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}
