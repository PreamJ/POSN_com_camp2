#include <bits/stdc++.h>
using namespace std;

int binomialCoeff(int n, int k, int** dp) {
    if (dp[n][k] != -1) {
        return dp[n][k];
    }
    if (k == 0 || k == n) {
        dp[n][k] = 1;
        return dp[n][k];
    }
    dp[n][k] = binomialCoeff(n-1, k-1, dp) + binomialCoeff(n-1, k, dp);
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    int** dp = new int*[n+1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[k+1];
        memset(dp[i], -1, sizeof(int)*(k+1));
    }
    cout << binomialCoeff(n, k, dp);
    return 0;
}