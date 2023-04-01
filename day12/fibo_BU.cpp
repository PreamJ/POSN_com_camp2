#include<bits/stdc++.h>
using namespace std;

// int fibo(int *arr, int n){
//     if(n<=1){
//         return n;
//     }
//     if(arr[n] == -1){
//         arr[n] = fibo(arr, n-1) + fibo(arr, n-2);
//     }
//     return arr[n];
// }

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     memset(arr, -1, sizeof(arr));
//     cout << fibo(arr, n);
// }

int fibo(int *arr, int n){
    if(n<=1){
        return n;
    }
    if(arr[n] == -1){
        arr[n] = fibo(arr, n-1) + fibo(arr, n-2);
    }
    return arr[n];
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n + 1];
    memset(arr, -1, (n + 1) * sizeof(int));
    cout << fibo(arr, n);
    delete[] arr;
    return 0;
}
