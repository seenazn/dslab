#include <stdio.h>
#include <stdlib.h>

#define MAX 10// Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Array to track visited nodes
int queue[MAX];     // Queue for BFS
int front = -1, rear = -1; // Queue pointers

// Function to add an element to the queue
void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = vertex;
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front++];
}

// Function to perform BFS
void bfs(int startVertex, int n) {
    enqueue(startVertex);
    visited[startVertex] = 1;

    printf("BFS Traversal: ");
    while (front <= rear) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
        visited[i] = 0;
    }

    // Input edges
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // Add edge u -> v
        adj[v][u] = 1;  // For undirected graph, add edge v -> u
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Perform BFS
    bfs(startVertex, n);

    return 0;
}
