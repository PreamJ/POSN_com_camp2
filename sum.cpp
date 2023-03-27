#include<bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    if(a%2 != 0){
        for(int i=0; i<a; i++){
            for(int j=0; j<a; j++){
                if(i+j == (a-1)/2) cout << "*";
                else if(i+j == a-1){
                    cout << "*";
                }
                else cout << "-";
            }
            cout << "\n";
        }
    }
    else{
        for(int i=0; i<a; i++){
            for(int j=0; j<a-1; j++){
                if(i<a/2){
                    if(i+j == (a/2)-1 || i+j == a-2) cout << "*";
                    else cout << "-";
                }
                else{
                    if(i+j == a/2 || i+j == a) cout << "*";
                    else cout << "-";
                }
            }
            cout << "\n";
        }
    }
}