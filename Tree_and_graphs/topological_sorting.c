#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Adjacency List Node
struct Node {
    int data;
    struct Node* next;
};

// Graph representation and in-degree array
struct Node* graph[MAX_VERTICES];
int in_degree[MAX_VERTICES];

// Queue for Kahn's algorithm
int queue[MAX_VERTICES];
int front = 0, rear = -1;

void addEdge(int u, int v) {
    // Add directed edge u -> v
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = graph[u];
    graph[u] = newNode;
    in_degree[v]++; // Increment in-degree of the destination vertex
}

void enqueue(int item) {
    if (rear >= MAX_VERTICES - 1) return;
    if (front > rear) front = 0; // Reset front if queue was empty
    queue[++rear] = item;
}

int dequeue() {
    if (front > rear) return -1;
    return queue[front++];
}

void initializeGraph(int V) {
    for(int i = 0; i < V; i++) {
        graph[i] = NULL;
        in_degree[i] = 0;
    }
    front = 0; 
    rear = -1;
}

void topologicalSort(int V) {
    int count = 0;
    
    // 1. Initialize queue with all vertices having in-degree 0
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) enqueue(i);
    }

    printf("Topological Sort Order: ");
    while (front <= rear) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        // 2. Iterate through all neighbors of u
        struct Node* temp = graph[u];
        while (temp) {
            int v = temp->data;
            in_degree[v]--; // Decrease in-degree
            
            // 3. If in-degree becomes 0, enqueue the neighbor
            if (in_degree[v] == 0) enqueue(v);
            temp = temp->next;
        }
    }
    printf("\n");

    if (count != V) {
        printf("A cycle was detected (Graph is not a DAG). Topological sort cannot be fully performed.\n");
    }
}

int main() {
    int V = 6; 
    initializeGraph(V);

    // Graph setup (Example: Course dependencies)
    // 5 -> 2, 5 -> 0, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);
    
    topologicalSort(V); 

    return 0;
}
