#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reversePart(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void rotateLeft(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n; // In case d > n

        // Step 1: Reverse first d elements
        reversePart(arr, 0, d - 1);

        // Step 2: Reverse remaining n-d elements
        reversePart(arr, d, n - 1);

        // Step 3: Reverse whole array
        reversePart(arr, 0, n - 1);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;
    Solution obj;
    obj.rotateLeft(arr, d);

    for (int x : arr) cout << x << " ";
    return 0;
}
