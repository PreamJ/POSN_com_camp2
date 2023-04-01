#include <bits/stdc++.h>
using namespace std;

int main() {
    int change, n;
    cin >> change >> n;
    int value[n];
    int table[change+1];

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    table[0] = 0;
    for (int i = 1; i <= change; i++) {
        table[i] = INT_MAX;
    }

    for (int i = 1; i <= change; i++) {
        for (int j = 0; j < n; j++) {
            if (value[j] <= i) {
                int sub_res = table[i - value[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i]) {
                    table[i] = sub_res + 1;
                }
            }
        }
    }

    if (table[change] == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << table[change] << endl;
    }
    return 0;
}
