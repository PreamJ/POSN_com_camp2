#include<bits/stdc++.h>
using namespace std;
/*
struct for linked list
struct adj{
    int vertex;
    int cost;
    struct adj *next;
};

struct 

typedef struct adj *adjlist;


int main(){
    int n;
    cout << "Enter number of city : ";
    cin >> n;
    int arr[n];
}
*/

/*
#define V 4
#define MAX 1000000
int tsp(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
    int min_cost = MAX;
    while(next_permutation(vertex.begin(), vertex.end()))
    {
        int current_cost = 0;
        int j = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_cost += graph[j][vertex[i]];
            j = vertex[i];
        }
        current_cost += graph[j][s];
        min_cost = min(min_cost, current_cost);
        return min_cost;
	}
}
int main()
{
    int graph[][V] = { { 0, 10, 15, 20 },{ 10, 0, 35, 25 },{ 15, 35, 0, 30 },{ 20, 25, 30, 0 } };                      
    int s = 0;
    cout << tsp(graph, s) << endl;
    return 0;
}
*/  
/*
const int N = 10;

int n; // number of cities
int dist[N][N]; // distance matrix
int best_tour[N+1], curr_tour[N+1]; // best tour and current tour
bool visited[N]; // visited array to keep track of visited cities

int curr_cost = 0; // current cost of the tour
int best_cost = INT_MAX; // best cost of the tour

void tsp(int depth) {
    if(depth == n) {
        // if all cities are visited, check if the current tour is better than the best tour
        if(curr_cost + dist[curr_tour[depth-1]][curr_tour[0]] < best_cost) {
            best_cost = curr_cost + dist[curr_tour[depth-1]][curr_tour[0]];
            for(int i=0; i<n; i++) {
                best_tour[i] = curr_tour[i];
            }
            best_tour[n] = curr_tour[0];
        }
        return;
    }
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            curr_tour[depth] = i;
            visited[i] = true;
            curr_cost += dist[curr_tour[depth-1]][i];
            tsp(depth+1);
            curr_cost -= dist[curr_tour[depth-1]][i];
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    // input distance matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dist[i][j];
        }
    }

    // set initial values
    for(int i=0; i<n; i++) {
        visited[i] = false;
        curr_tour[i] = -1;
        best_tour[i] = -1;
        for(int j=0; j<n; j++) {
            dist[i][j] = 0;
        }
    }

    // set starting city
    curr_tour[0] = 0;
    visited[0] = true;

    // find best tour
    tsp(1);

    // output best tour and cost
    cout << "Best tour: ";
    for(int i=0; i<=n; i++) {
        cout << best_tour[i] << " ";
    }
    cout << endl;
    cout << "Best cost: " << best_cost << endl;

    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

void tsp(vector<vector<int>>& distances, int n) {
    vector<int> cities;
    for (int i = 0; i < n; i++) {
        cities.push_back(i);
    }
    int minDistance = INT_MAX;
    vector<int> minPath;
    do {
        int tourDistance = 0;
        for (int i = 0; i < n; i++) {
            int currentCity = cities[i];
            int nextCity = cities[(i + 1) % n];
            tourDistance += distances[currentCity][nextCity];
        }
        if (tourDistance < minDistance) {
            minDistance = tourDistance;
            minPath = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    cout << "Min tour distance : " << minDistance << endl;
    cout << "Path way : ";
    for (int i = 0; i < n; i++) {
        cout << minPath[i] << " ";
    }
    cout << minPath[0] << endl;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    vector<vector<int>> distances(n, vector<int>(n));
    cout << "Enter the distances between the cities: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distances[i][j];
        }
    }
    tsp(distances, n);

    return 0;
}