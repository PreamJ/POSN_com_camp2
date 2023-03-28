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