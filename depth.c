#include <stdio.h>
#include <stdlib.h>

#define MAX 10// Maximum number of vertices

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Array to track visited nodes

// Function to perform DFS
void dfs(int vertex, int n) {
    printf("%d ", vertex); // Print the visited vertex
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, n); // Recursively visit adjacent vertices
        }
    }
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

    // Perform DFS
    printf("DFS Traversal: ");
    dfs(startVertex, n);
    printf("\n");

    return 0;
}
