#include<bits/stdc++.h>
using namespace std;

int main(){
    int row, column;
    cin >> row >> column;
    char arr[row][column];
    bool sit[row+2][column+2];
    memset(sit, false, (row+1)*(column+1));
    for(int i=1; i<=row; i++){
        for(int j=1; j<=column; j++){
            cin >> arr[i][j];
            if(arr[i][j] == '0') sit[i][j] = false;
            else sit[i][j] = true;
        }
    }
    int count = 1;
    for(int i=1; i<=row; i++){
        for(int j=1; j<=column; j++){
            if(sit[i][j] == true){
                
            }
        }
    }
    cout << count;
}
/*
4 5
10011
00001
01100
10011
output 3

4 4
0010
1010
0100
1111
output 1
*/