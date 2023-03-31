#include<bits/stdc++.h>
using namespace std;
int sell = INT_MIN;
int maxprice(int n, int *price){
    for(int i=1; i<n/2; i++){
        int add, current;
        add = n-i;
        current = price[add] + price[i];
        if(current > sell) sell = current;
    }
    return sell;
}


int main(){
    int n;
    cin >> n;
    int price[n];
    for(int i=1; i<=n; i++){
        cin >> price[i];
    }
    cout << max(maxprice(n, price), price[n]);

}