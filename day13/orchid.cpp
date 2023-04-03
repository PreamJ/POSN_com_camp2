#include<bits/stdc++.h>
using namespace std;

int replace(vector<int> arr, int n){
    int count=0;
    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1]){
            arr[i] = arr[i-1];
            count++;
        }
    }
    return count;
}

int main(){
    int n, x;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << replace(arr, n);
}
/*
4
5
4
3
6
output 2


10
1
2
3
4
5
6
7
1
2
3
output 3
*/