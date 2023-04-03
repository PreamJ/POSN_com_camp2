#include<bits/stdc++.h>
using namespace std;

int main(){
    int num, size, r, x;
    cin >> num >> size;
    vector<vector<int>> order(num);
    for(int i=0; i<num; i++){
        cin >> r;
        for(int j=0; j<r; j++){
            cin >> x;
            order[i].push_back(x);
        }
    }
}

/*
3 5
8
5 5 5 5 5 5 5 5 
5
5 5 5 2 2
4
2 2 2 2
*/