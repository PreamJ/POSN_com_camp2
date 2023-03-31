#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    int n;
    int runner = 0, temp=0, comp =0 , ans=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> runner;
        if(temp == 0){
            temp = runner;
        }
        else if(temp == runner){
            temp = 0;
        }
        else if(runner > temp){
            comp = temp;
            temp = runner;
        }
        else ans = runner;
        ans = max(ans, comp);
    }
}