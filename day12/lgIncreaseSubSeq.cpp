#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> v;
int CeilIndex(vector<int> &v, int l, int r, int key){
    while(r - l > 1){
        int m = l + (r - l) / 2;
        if(v[m] >= key) r = m;
        else l = m;
    } return r;
}
int LIS(){
    if(n == 0) return 0;
    vector<int> tail(n, 0);
    int length = 1;
    tail[0] = v[0];
    for(size_t i = 1; i < n; i++){
        if(v[i] < tail[0]) tail[0] = v[i];
        else if(v[i] > tail[length - 1]) tail[length++] = v[i];
        else tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    } return length;
}
  
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> e;
        v.push_back(e);
    }
    cout << LIS() << endl;
    return 0;
}

/***
 * 12
 * 2 12 8 0 23 11 52 31 51 59 80 22
 ***/