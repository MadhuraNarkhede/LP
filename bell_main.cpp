#include <iostream>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to implement the Bellman-Ford algorithm
void bellmanFord(Edge edges[], int V, int E, int src) {
    // Array to store the shortest distance to each vertex
    int dist[V];

    // Initialize distances from the source to all vertices as infinity
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            // If the edge can be relaxed, update the distance
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << "\tINF" << endl;
        else
            cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V, E, src;

    // Input the number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Array to store all edges
    Edge edges[E];

    // Input edges (source, destination, weight)
    cout << "Enter source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        cout << "Edge " << i + 1 << " - Source: ";
        cin >> edges[i].src;
        cout << "Destination: ";
        cin >> edges[i].dest;
        cout << "Weight: ";
        cin >> edges[i].weight;
    }

    // Input the source vertex
    cout << "Enter the source vertex: ";
    cin >> src;

    // Call Bellman-Ford algorithm
    bellmanFord(edges, V, E, src);

    return 0;
}