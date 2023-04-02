#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V, E;

public:
    Edge* edge;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        edge = new Edge[E];
    }

    void addEdge(int src, int dest, int weight, int i)
    {
        edge[i].src = src;
        edge[i].dest = dest;
        edge[i].weight = weight;
    }

    void BellmanFord(int src)
    {
        int dist[V];
        for (int i = 0; i < V; ++i)
            dist[i] = INT_MAX;
        dist[src] = 0;

        for (int i = 0; i < V - 1; ++i) {
            for (int j = 0; j < E; ++j) {
                int u = edge[j].src;
                int v = edge[j].dest;
                int weight = edge[j].weight;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }

        for (int i = 0; i < E; ++i) {
            int u = edge[i].src;
            int v = edge[i].dest;
            int weight = edge[i].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative-weight cycle. Shortest path not possible." << endl;
                return;
            }
        }

        cout << "Shortest distance from source " << src << " to all other vertices:\n";
        for (int i = 0; i < V; ++i)
            cout << i << ": " << dist[i] << endl;
    }
};

int main()
{
    int V, E, src;
    cout << "Enter the number of vertices and edges of the graph: ";
    cin >> V >> E;

    Graph graph(V, E);

    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cout << "Enter the source, destination, and weight of edge " << i+1 << ": ";
        cin >> src >> dest >> weight;

        graph.addEdge(src, dest, weight, i);
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    graph.BellmanFord(src);

    return 0;
}