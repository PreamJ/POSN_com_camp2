#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     vector<int> newarr;
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//         if(i!=0 && arr[i]!=arr[i-1]) newarr.push_back(arr[i]);
//     }
//     if(arr[0] != arr[1]) newarr.push_back(arr[0]);
//     for (int i = 0; i < newarr.size(); i++){
//         cout << newarr[i] << " ";
//     }
//     //cout << *max_element(newarr.begin(), newarr.end());
// }

int bef,now,N,s,ans;
int main(){
    std :: cin >> N;
    for (int i = 0 ; i < N ; i++){
        std :: cin >> now ;
        if (bef == 0) bef = now;
        else if (now == bef) bef = 0;
        else if (now > bef) {s = bef; bef = now;}
        else s = now;
        ans = std :: max(ans,s);
    }
    if (ans == INT_MAX) std :: cout << "0";
    else std :: cout << ans;
}
