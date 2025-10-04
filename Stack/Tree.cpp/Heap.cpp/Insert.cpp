#include <bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int currentSum = nums[0];
    int maxSum = nums[0];

    int start = 0, ansStart = 0, ansEnd = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] > currentSum + nums[i]) {
            currentSum = nums[i];
            start = i; // new subarray starts
        } else {
            currentSum += nums[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            ansStart = start;
            ansEnd = i;
        }
    }

    // Print results
    cout << "Maximum Subarray Sum = " << maxSum << endl;
    cout << "Subarray = [ ";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArray(nums);
    return 0;
}
