#include<bits/stdc++.h>
using namespace std;

int weird(int n){
    if(n==1) { return 0;}
    else if(n%2==0){
        n = n/2;
        cout << n << " ";
        return weird(n);
    }
    else{
        n = n*3+1;
        cout << n << " ";
        return weird(n);
    }
}

int main(){
    int n;
    cin >> n;
    cout << n << " ";
    weird(n);
}