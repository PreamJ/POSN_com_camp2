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

int tsp(int graph[n][n], int n){
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

int main(){
    int n;
    cin >> n;
    int graph[4][4] = { { 0, 10, 15, 20 },{ 10, 0, 35, 25 },{ 15, 35, 0, 30 },{ 20, 25, 30, 0 } };
    // int graph[n][n];
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cin >> graph[i][j];
    //     }
    // }

    
}