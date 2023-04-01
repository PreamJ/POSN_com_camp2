#include<bits/stdc++.h>
using namespace std;
// bottom up

// int main() {
//     int n, k;
//     cin >> n >> k;

//     int arr[n + 2][k + 2];
//     memset(arr, 0, sizeof(arr));

//     for (int i = 1; i <= n+1; i++) {
//         for (int j = 1; j <= k+1; j++) {
//             if (i == j || j == 1) {
//                 arr[i][j] = 1;
//             }
//             else {
//                 arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//             }
//         }
//     }
//     cout << arr[n+1][k+1] << endl;
//     return 0;
// }


// top down
int fib(int n, int k){
    int arr[n][k];
    if(n==k && k==0){
        return arr[n][k] = 1;
    }
    else{
        arr[n][k] = fib(n-1, k-1) + fib(n-1, k);
        return arr[n][k];
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << fib(n, k);
}