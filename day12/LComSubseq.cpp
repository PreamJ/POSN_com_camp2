#include<bits/stdc++.h>
using namespace std;

int LCS(char *x, int n, char *y, int m){
    int table[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i == 0 || j == 0){
                table[i][j] = 0;
            }
            else if(x[i-1] == y[j-1]){
                table[i][j] = 1 + table[i-1][j-1];
            }
            else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    return table[n][m];
}

int main(){
    int n,m;
    cin >> n >> m;
    char x[n];
    char y[m];
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    for(int i=0; i<m; i++){
        cin >> y[i];
    }
    cout << LCS(x, n, y, m);

}

/*
8 10
analysis
algorithms
*/