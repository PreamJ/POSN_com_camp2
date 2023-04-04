#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n;
    int arr[n];
    set<int> distinct;
    for(int i=0; i<n; i++){
        cin >> x;
        distinct.insert(x);
    }
    cout << distinct.size();
}