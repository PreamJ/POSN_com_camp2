#include<bits/stdc++.h>
using namespace std;

void printSubset(const vector<int>& subset) {
    cout << "{ ";
    for (int i : subset) {
        cout << i << " ";
    }
    cout << "}" << endl;
}
bool subsetSum(const vector<int>& set, int target, vector<int>& subset, int index) {
    if (target == 0) {
        printSubset(subset);
        return true;
    }

    if (index >= set.size() || target < 0) {
        return false;
    }
    subset.push_back(set[index]);
    bool found = subsetSum(set, target - set[index], subset, index + 1);
    subset.pop_back();
    found = subsetSum(set, target, subset, index + 1) || found;

    return found;
}

int main() {
    int n, target;
    cout << "Enter the size of the set: ";
    cin >> n;
    vector<int> set(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> subset;
    if (!subsetSum(set, target, subset, 0)) {
        cout << "Thre is no subset that make up to target number." << endl;
    }

    return 0;
}