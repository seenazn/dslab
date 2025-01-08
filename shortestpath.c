#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
// Function to find the vertex with the minimum distance value, from the set of vertices not yet processed
int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, minIndex;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
// Function to print the distance array
void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}
// Function to implement Dijkstra's algorithm
void dijkstra(int **graph, int V, int src) {
    int dist[V]; // Output array to hold shortest distance from src to i
    int sptSet[V]; // sptSet[i] will be 1 if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);
        // Mark the picked vertex as processed
        sptSet[u] = 1;
        // Update dist[] value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not in sptSet, there's an edge from u to v, and total weight of path from src to v through u is smaller than current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // Print the calculated shortest distances
    printSolution(dist, V);
}
int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    // Allocate memory for the graph and initialize all edges to 0
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight; // For undirected graph
    }
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, V, src);
    // Free allocated memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
