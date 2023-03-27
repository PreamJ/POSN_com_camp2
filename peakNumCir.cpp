#include<bits/stdc++.h>
using namespace std;

int findPeak(int nums[], int left, int right, int n) {
    int mid = (left + right) / 2;

    if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == n - 1 || nums[mid] >= nums[(mid + 1) % n])) {
        cout << mid; // mid element is a peak element
    }
    else if (mid > 0 && nums[mid - 1] > nums[mid]) {
        // peak element lies in the left half of the array
        return findPeak(nums, left, mid - 1, n);
    }
    else {
        // peak element lies in the right half of the array
        return findPeak(nums, mid + 1, right, n);
    }
}

int main() {
    int nums[] = { 8, 9, 10, 2, 7, 6 };
    int n = sizeof(nums) / sizeof(nums[0]);

    int peak = findPeak(nums, 0, n - 1, n);

    cout << "Peak element: " << peak << endl;

    return 0;
}