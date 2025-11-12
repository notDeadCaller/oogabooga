#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* graph[MAX_VERTICES];
int visited[MAX_VERTICES];

void addEdge(int u, int v) {
    struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
    newNode1->data = v;
    newNode1->next = graph[u];
    graph[u] = newNode1;

    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    newNode2->data = u;
    newNode2->next = graph[v];
    graph[v] = newNode2;
}

int isCyclicUtil(int u, int parent) {
    visited[u] = 1;
    
    struct Node* temp = graph[u];
    while (temp) {
        int v = temp->data;

        if (!visited[v]) {
            if (isCyclicUtil(v, u)) return 1;
        } 
        
        else if (v != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int isCyclic(int V) {
    for(int i = 0; i < V; i++) visited[i] = 0;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, -1)) return 1;
        }
    }
    return 0;
}

int main() {
    int V = 5; 
    for(int i = 0; i < V; i++) graph[i] = NULL;

    // Graph with a cycle (0-1-2-0)
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0); 
    addEdge(1, 3);
    addEdge(3, 4);

    if (isCyclic(V)) {
        printf("Graph contains cycle.\n");
    } else {
        printf("Graph does not contain cycle.\n");
    }

    return 0;
}
