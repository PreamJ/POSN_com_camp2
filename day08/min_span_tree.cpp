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

    int find(int parent[], int i)
    {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(int parent[], int x, int y)
    {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    void KruskalMST()
    {
        Edge result[V]; 
        int e = 0; 

        sort(edge, edge + E, [](Edge a, Edge b) {
            return a.weight < b.weight;
        }); 
        int parent[V];
        memset(parent, -1, sizeof(parent)); 

        for (int i = 0; i < E; ++i) {
            int x = find(parent, edge[i].src);
            int y = find(parent, edge[i].dest);

            if (x != y) {
                result[e++] = edge[i];
                Union(parent, x, y);
            }
        }

        cout << "Minimum Spanning Tree of the given graph :\n";
        for (int i = 0; i < e; ++i)
            cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    }
};

int main()
{
    int V, E;
    cout << "number of vertices and edges of the graph : ";
    cin >> V >> E;

    Graph graph(V, E);

    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cout << "source, destination, and weight of edge " << i+1 << ": ";
        cin >> src >> dest >> weight;

        graph.addEdge(src, dest, weight, i);
    }

    graph.KruskalMST();

    return 0;
}