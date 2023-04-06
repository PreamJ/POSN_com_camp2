#include<bits/stdc++.h>
using namespace std;

int even(vector<int> arr, int n){
    int maxA=0, maxB=0;
    for(int i=0; i<n; i+=2){
        maxA += arr[i];
    }
    for(int j=1; j<n; j+=2){
        maxB += arr[j];
    }
    return max(maxA, maxB);
}

int odd(vector<int> arr, vector<int> temp, int n){
    vector<int> oddarr;
    for(int i=0; i<n; i++){
        arr.erase(arr.begin()+i);
        oddarr.push_back(even(arr, n-1));
        arr.insert(arr.begin()+i, temp[i]);
    }
    int ans=oddarr[0];
    for(int i=1; i<oddarr.size(); i++){
        if(oddarr[i]>ans) ans = oddarr[i];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr, temp;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
        temp.push_back(x);
    }
    if(n%2==0){
        cout << even(arr, n);
    }
    else{
        cout << odd(arr, temp, n);
    }
}
/*
6
10
3
2
5
7
8
output 19

2
11
16
output 16

5
2
5
4
8
10
output 15
*/
