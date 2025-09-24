#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;  // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    // Call twoSum
    vector<int> ans = sol.twoSum(nums, target);

    // Output result
    if (!ans.empty()) {
        cout << "Indices: " << ans[0] << ", " << ans[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }
    return 0;
}
