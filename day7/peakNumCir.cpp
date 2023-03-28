#include<bits/stdc++.h>
using namespace std;

void Peak(int nums[], int left, int right, int n, int &peakCount, int *peaks) {
    int mid = (left + right) / 2;
    if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == n - 1 || nums[mid] >= nums[(mid + 1) % n])) {
        peaks[peakCount++] = mid;
    }
    if (mid > 0 && nums[mid - 1] > nums[mid]) {
        Peak(nums, left, mid - 1, n, peakCount, peaks);
    }
    if (mid < n - 1 && nums[mid + 1] > nums[mid]) {
        Peak(nums, mid + 1, right, n, peakCount, peaks);
    }
}
int main() {
    int nums[] = {2,3,1,4,5,6};
    int n = sizeof(nums) / sizeof(nums[0]);
    int *peaks = new int[n];
    int peakCount = 0;
    Peak(nums, 0, n - 1, n, peakCount, peaks);
    if (peakCount == 0) {
        cout << "No peak element found." << endl;
    }
    else {
        for (int i = 0; i < peakCount; i++) {
            cout << peaks[i] << " ";
        }
        cout << endl;
    }
    delete[] peaks;
    return 0;
}