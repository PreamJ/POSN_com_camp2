#include<bits/stdc++.h>
using namespace std;

void optimalPrice(int com, vector<vector<int>> stock, int store, vector<vector<int>> pos, int *start, int *distanceCost){
    int answer = 0, k=stock[0][0], m=stock[0][1], c=stock[0][2];
    if(store == 1){
        cout << *distanceCost;
    }
    else{
        
    }
    // else{
        
    //     for(int i=0; i<store; i++){
    //         if(k>=com && m>=com && c>=com){
    //             answer += distanceCost[i];
    //             cout << answer;
    //             break;
    //         }
    //         k += stock[i][0];
    //         m += stock[i][1];
    //         c += stock[i][2];
    //         answer +=distanceCost[i];
    //     }
    // }
}

int main(){
    int com, start[3];
    cin >> com >> start[0] >> start[1] >> start[2];
    int store;
    cin >> store;
    vector<vector<int>> pos(store, vector<int>(3));
    vector<vector<int>> stock(store, vector<int>(3));
    for(int i=0; i<store; i++){
        cin >> pos[i][0] >> pos[i][1] >> pos[i][2];
        cin >> stock[i][0] >> stock[i][1] >> stock[i][2];
    }
    int distanceCost[store];
    for(int i=0; i<store; i++){
        distanceCost[i] = 
        (pos[i][0] - start[0])*(pos[i][0] - start[0]) +
        (pos[i][1] - start[1])*(pos[i][1] - start[1]) +
        (pos[i][2] - start[2])*(pos[i][2] - start[2]);
    }
    optimalPrice(com, stock, store, pos, start, distanceCost);
}

/*
1
0 0 0
2
10 0 0
2 5 7
0 10 0
0 3 9
output : 100


5
0 0 0
5
60 34 56
0 5 7
90 41 92
1 7 8
24 61 81
6 8 8
41 86 70
5 6 7
46 97 85
9 2 4
output 10542
*/