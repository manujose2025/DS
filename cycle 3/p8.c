#include <stdio.h>
#include <limits.h>

#define V 6

void printGraph(int graph[V][V]) 
{
    printf("Graph:\n");
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int minDistance(int distance[], int visited[])  
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) 
    {
        if (!visited[v] && distance[v] <= min) 
        {
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) 
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("-> %d ", j);
}

void printSolution(int distance[], int parent[], int dest) 
{
    printf("\nShortest Distance from Source to Destination: %d\n", distance[dest]);
    printf("Shortest Path: %d ", parent[dest]);
    printPath(parent, dest);
    printf("\n");
}

void dijkstra(int graph[V][V], int source, int dest) 
{
    int distance[V];
    int parent[V];
    int visited[V];
    for (int i = 0; i < V; i++) 
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }
    distance[source] = 0;
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(distance, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++) 
        {
            if (!visited[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) 
            {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printGraph(graph);
    printf("\nSource Vertex: %d\n", source);
    printf("Destination Vertex: %d\n", dest);
    printSolution(distance, parent, dest);
}

int main() 
{
    int graph[V][V] = 
    {
        {0, 1, 4, 0, 0, 0},
        {1, 0, 4, 2, 7, 0},
        {4, 4, 0, 3, 5, 0},
        {0, 2, 3, 0, 4, 6},
        {0, 7, 5, 4, 0, 7},
        {0, 0, 0, 6, 7, 0}
    };
    int source = 0;
    int destination = 5;
    dijkstra(graph, source, destination);
    return 0;
}
