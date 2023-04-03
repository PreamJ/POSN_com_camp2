#include<bits/stdc++.h>
using namespace std;


int main(){
    int k, n;
    cin >> k >> n;
    int x;
    vector<int> price;
    for(int i=0; i<n; i++){
        cin >> x;
        price.push_back(x);
    }
    sort(price.begin(), price.end());
    // cout << price[0] << endl;
    vector<int> table;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(j>=i+4) break;
            else{
                int ans = price[j]-price[i];
                table.push_back(ans);
                // cout << ans << endl;
                // cout << table[i] << endl;
            }
        }
        // cout << table[i] << endl;
    }
    if(table.empty()==true) cout << "0" << endl;
    else{
        int out=0;
        sort(table.begin(), table.end());
        for(int i=0; i<k; i++){
            out += table[i];
        }
        cout << out;
    }
    // cout << table[0];
}
/*
3 12
11 14 15 18 20 22 24 27 30 35 35 40
output 3

2 8
10 10 10 10 10 20 20 20
output 0

4 15
2 5 35 38 40 48 89 92 107 123 145 155 160 190 191
output 9
*/