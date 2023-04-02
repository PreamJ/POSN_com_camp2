#include<bits/stdc++.h>
using namespace std;

// int check(vector<vector<char>> sit, int m, int n, int count){
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if((sit[i-1][j-1] == "0") && (sit[i-1][j] == "0") && (sit[i-1][j+1] == "0") && 
//             (sit[i][j-1] == "0") && (sit[i][j] == "0") && (sit[i][j+1] == "0") &&
//             (sit[i+1][j-1] == "0") && (sit[i+1][j] == "0") && (sit[i+1][j+1] == "0")){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main(){
//     int m, n;
//     cin >> m >> n;
//     vector<vector<char>> sit;
//     int count = 1;
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             cin >> sit[i][j];
//         }
//     }
//     cout << check(sit, m, n, count);
// }
