#include<bits/stdc++.h>
using namespace std;

int towers(int n, char frompeg, char topeg, char auxpeg, int &count){
    if(n==1){
        count++;
        return count;
    }
    towers(n-1, frompeg, auxpeg, topeg, count);
    count ++;
    towers(n-1, auxpeg, topeg, frompeg, count);
    return count;
}
int main(){
    int n; 
    int count = 0;
    cin >> n;
    cout << towers(n, *"a", *"c", *"b", count) << endl;
}