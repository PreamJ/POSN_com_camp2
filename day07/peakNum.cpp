#include<bits/stdc++.h>
using namespace std;

int main(){
    int m;
    cin >> m;
    int arr[m];
    for(int i=0; i<m; i++){
        cin >> arr[i];
    }
    if(arr[0]>arr[1]) cout << 0 << " ";
    
    for(int i=1; i<m-1; i++){
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1]) cout << i << " ";
    }

    if(arr[m-1] > arr[m-2]) cout << m;
}