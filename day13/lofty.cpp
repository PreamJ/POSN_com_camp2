#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,x=1,y,diff;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> table;
    for(int i=1; i<n-1; i++){ //ไม่ลูปตัวแรกกับสุดท้าย
        if(arr[i-1] > arr[i] && arr[i+1] > arr[i]){
            
            while(arr[i-x]<arr[i-x+1]){
                y = 1;
                while(arr[i+y]<arr[i+y-1]){
                    diff = abs(arr[i-x]-arr[i+y]);
                    table.push_back(diff);
                    y++;
                }
                x++;
            }
        }
    }
    int ans = table[0];
    for(int i=1; i<table.size(); i++){
        if(ans<table[i]) ans = table[i];
    }
    if(table.size() == 0) cout << "0" << endl << "-1";
    else cout << table.size() << endl << ans << endl;
}
/*
8
10 8 2 5 7 4 1 6
output 6 17

13
5 10 20 30 10 12 15 18 29 28 12 27 55
output 8 84

10
1 2 3 4 5 6 6 4 3 2
output 0 -1
*/