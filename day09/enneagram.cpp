#include<bits/stdc++.h>
using namespace std;

int count(int *arr, int n, int m){
    int left = 0;
    int storage[9] = {};
    for(int i=0; i<n; i++){
        for(int j=0; j<9; j++){
            if(arr[i] == j+1){
                storage[j]++;
            }
        }
    }
    for(int i=0; i<9; i++){
        left += storage[i]%m;
    }
    return left;
}

int main(){
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cout << count(arr, n, m);
}