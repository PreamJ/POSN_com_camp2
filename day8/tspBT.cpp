#include<bits/stdc++.h>
using namespace std;


int tsp(vector<vector<int>> &graph, vector<int> &path, vector<bool> &visited, int curr_cost, int n, int curr_city, int start_city) {
    if (visited == vector<bool>(n, true)) {
        path.push_back(start_city);
        return curr_cost + graph[curr_city][start_city];
    }

    int min_cost = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);
            int cost = tsp(graph, path, visited, curr_cost + graph[curr_city][i], n, i, start_city);
            if (cost < min_cost) {
                min_cost = cost;
            }
            path.pop_back();
            visited[i] = false;
        }
    }
    return min_cost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the distance matrix: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> path;
    vector<bool> visited(n, false);
    visited[0] = true;
    path.push_back(0);

    int min_cost = tsp(graph, path, visited, 0, n, 0, 0);

    cout << "The minimum cost of the TSP tour is: " << min_cost << endl;
    cout << "The path is: ";
    for (int i = 0; i < n; ++i) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}