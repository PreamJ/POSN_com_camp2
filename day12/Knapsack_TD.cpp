#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity, int n, vector<vector<int>>& memo){
    if(n==0 || capacity==0){
        return 0;
    }
    if(memo[n][capacity] != -1){
        return memo[n][capacity];
    }
    if(weights[n-1] > capacity){
        memo[n][capacity] = knapsack(weights, values, capacity, n-1, memo);
    }
    else{
        memo[n][capacity] = max(knapsack(weights, values, capacity, n-1, memo), values[n-1] + knapsack(weights, values, capacity-weights[n-1], n-1, memo));
    }
    return memo[n][capacity];
}

int main(){
    int n, capacity;
    cin >> n >> capacity;
    vector<int> weights(n), values(n);
    for(int i=0; i<n; i++){
        cin >> values[i];
    }
    for(int i=0; i<n; i++){
        cin >> weights[i];
    }
    vector<vector<int>> memo(n+1, vector<int>(capacity+1, -1));
    int result = knapsack(weights, values, capacity, n, memo);
    cout << result << endl;
    return 0;
}
/*
4 7
1 4 5 7
1 3 4 5
*/