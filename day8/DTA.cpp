#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

class Graph {
    int V;
    vector<pair<int, int>>* adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void Dijkstra(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, INF);
        dist[src] = 0;

        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& i : adj[u]) {
                int v = i.first;
                int weight = i.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
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

    Graph graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cout << "Enter the source, destination, and weight of edge " << i+1 << ": ";
        cin >> u >> v >> w;

        graph.addEdge(u, v, w);
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    graph.Dijkstra(src);

    return 0;
}