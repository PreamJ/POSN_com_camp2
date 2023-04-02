#include<bits/stdc++.h>
using namespace std;

int square(int n){
    if(n==0) return 1;
    return 4*square(n-1);
}
int fac(int n){
    if(n==1) return 1;
    return n*fac(n-1);
}
int sum(int n){
    if(n==1) return 1;
    return n+sum(n-1);
}
int main(){ 
    //int s;
    // cin >> s;
    // cout << square(s);
    int  f;
    cin >> f;
    cout << fac(f) << endl;
}