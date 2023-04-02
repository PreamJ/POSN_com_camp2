#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100; 
int n, m; 
vector<int> adj[MAXN+1];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++) {
        cout << u << ": ";
        for (int v : adj[u]) {
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}