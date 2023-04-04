#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, maxbwid;
    cin >> n >> maxbwid;
    int report[n][3];
    for(int i=0; i<n; i++){
        cin >> report[i][0] >> report[i][1] >> report[i][2];
    }

}

/*
6 50
2 80 30
19 65 25
30 102 10
102 150 45
160 185 14
140 180 25

output
19 65
102 102
140 150



7 30
21 30 15
26 35 14
31 40 15
36 45 14
41 50 15
49 60 20
55 62 12

output
49 50
55 60
*/