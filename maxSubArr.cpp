#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return(a>b) ? a: b;
}
int max(int a, int b, int c){
    return max(max(a,b),c);
}

int maxCroSub(int arr[], int l, int m, int h){
    int sum = 0;
    int left = INT_MIN;
    for(int i=m; i>=1; i--){
        sum = sum +arr[i];
        if(sum > left){
            left = sum;
        }
    }
    sum = 0;
    int right = INT_MIN;
    for (int i = m; i<=h; i++){
        sum = sum +arr[i];
        if(sum > right){
            right = sum;
        }
    }
    return max(left +right -arr[m], right, left);
}

int maxSubArrSum(int arr[], int l, int h){
     if(l > h){
        return INT_MIN;
     }
     else if(l == h){
        return arr[l];
     }

     int m = (l+h)/2;
     return max(maxSubArrSum(arr, l, m - 1),
            maxSubArrSum(arr, m + 1, h),
            maxCroSub(arr, l, m, h));
}
int main(){

    int arr[] = { -8, 3, -5, 5, 0 };

    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArrSum(arr, 0, n - 1);
    printf("%d\n", max_sum);
    return 0;
}