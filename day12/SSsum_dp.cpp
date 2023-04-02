#include<bits/stdc++.h>
using namespace std;

bool subsetsum(int n, int sum, vector<int> arr){
    bool table[n+1][sum+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum+1; j++){
            if(j==0) table[i][j] = true;
            else if(i==0) table[i][j] = false;
            else if(j>arr[i-1]){
                table[i][j] = table[i-1][j];
            }
            else if(j<=arr[i-1]){
                table[i][j] = table[i - 1][j - arr[i - 1]] || table[i - 1][j];
            }
            // if(i==0 || j==0) table[i][j] = false;
            // else if(arr[i-1] == j) table[i][j] = true;
            // else if()
            // cout << table[i][j] << " ";
        }
        // cout << endl;
    }
    return table[n][sum+1];
}

int main(){
    int n, sum;
    vector<int> arr;
    cin >> n >> sum;
    for(int i=0; i<n; i++){
        int input;
        cin >> input;
        arr.push_back(input);
    }
    if(subsetsum(n, sum, arr) ==0) cout << "false";
    else cout << "true";
}
/*
6 9
3 3 4 4 12 5 2

4 6
1 3 5 7
*/
