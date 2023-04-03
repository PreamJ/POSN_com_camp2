#include<bits/stdc++.h>
using namespace std;

vector<int> table;

int jump(int distance, int n, vector<int> arr){
    int minus;
    for(int i=0; i<n; i++){
        int count = -1;
        for(int j=i+1; j<n; j++){
            minus = arr[j] - arr[i];
            if(minus>=distance){
                table.push_back(++count);
                break;
            }
            else{
                count++;
            }
        }
        // cout << table[i] << endl;
    }
    int ans=table[0];
    // cout << endl << table.size() << endl;
    for(int i=1; i<table.size(); i++){
        if(table[i]>ans) ans = table[i];
    }
    return ans;
}

int main(){
    int n, distance;
    cin >> n >> distance;
    vector<int> arr;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        arr.push_back(x);
    }
    // cout << endl;
    cout << jump(distance, n, arr);
}
/*
11 6
3
6
7
9
10
11
13
16
18
19
20
output 4

3 30000
2000
35000
55000
output 1
*/