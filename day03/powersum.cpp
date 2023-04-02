#include<bits/stdc++.h>
using namespace std;

int powerSum(int x, int n){
    if(x == 1) return 1;
    return pow(x, n) + powerSum(x-1, n);
}
int main(){ 
    int x, n;
    cin >> x >> n;
    cout << powerSum(x,n) << endl;
}