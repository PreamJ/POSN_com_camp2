#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[node] = true; 
    cout << node << " "; 

    
    for (int i = 0; i < graph[node].size(); i++) {
        int adj = graph[node][i];
        if (!visited[adj]) {
            dfs(adj, visited, graph); 
        }
    }
}
int main() {
    int n, m; 
    cin >> n >> m;

    vector<vector<int>> graph(n+1); 
    vector<bool> visited(n+1, false); 

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph);
        }
    }
    return 0;
}