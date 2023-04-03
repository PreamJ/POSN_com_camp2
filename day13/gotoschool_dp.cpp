#include<bits/stdc++.h>
using namespace std;

int avoiddog(vector<pair<int, int>> &doglocat, int row, int column){
    
}

int main(){
    int row, column, dog;
    cin >> column >> row >> dog;
    vector<pair<int, int>> doglocat(dog);
    for(int i=0; i<dog; i++){
        cin >> doglocat[i].first;
        cin >> doglocat[i].second;
    }
    avoiddog(doglocat, row, column);
}

/*
5 4
3
2 2
2 3
4 2
output : 5
*/