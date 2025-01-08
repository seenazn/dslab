
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the number of vertices
#define V 5

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (key[v] < min && mstSet[v] == 0)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to implement Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    // Initialize the keys and parent arrays
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    // Set the key of the starting vertex to 0
    key[0] = 0;
    parent[0] = -1;

    // Loop through all the vertices
    for (int count = 0; count < V - 1; count++) {
        // Find the vertex with the minimum key value
        int u = minKey(key, mstSet);

        // Mark the vertex as part of the MST
        mstSet[u] = 1;

        // Update the keys of the adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the MST
    printMST(parent, graph);
}

// Driver program
int main() {
    int graph[V][V] = {{0, 2, 0, 6, 0},
                          {2, 0, 3, 8, 5},
                          {0, 3, 0, 0, 7},
                          {6, 8, 0, 0, 9},
                          {0, 5, 7, 9, 0}};

    primMST(graph);

    return 0;
}
