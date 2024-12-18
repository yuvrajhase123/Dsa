#include <iostream>
#include <climits>
using namespace std;

#define V 5 // Number of nodes (landmarks)

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest distance from source to all other landmarks
void printSolution(int dist[]) {
    cout << "Landmark \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

// Dijkstra's algorithm to find the shortest path from source to all other landmarks
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array, dist[i] will hold the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as infinite and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance to the source itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update the dist[] values of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if and only if the edge u-v is smaller than the current dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    // Adjacency matrix representation of the graph (graph[u][v] = distance between u and v)
    int graph[V][V] = { {0, 10, 0, 0, 5},
                        {10, 0, 10, 30, 0},
                        {0, 10, 0, 50, 10},
                        {0, 30, 50, 0, 20},
                        {5, 0, 10, 20, 0} };
    
    // Source landmark (for example, landmark 0)
    int src = 0;

    // Run Dijkstra's algorithm
    dijkstra(graph, src);
    
    return 0;
}
