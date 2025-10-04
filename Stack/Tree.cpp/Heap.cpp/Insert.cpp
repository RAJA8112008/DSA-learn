#include <bits/stdc++.h>
using namespace std;

int maxValidPairs(vector<int>& a, vector<int>& b) {
    int n = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, count = 0;
    while(i < n && j < n) {
        if(a[i] > b[j]) {
            count++;
            i++; j++;
        } else {
            i++;
        }
        
    }
    return count;
}
int main() {
    vector<int> a = {4, 2, 5, 1};
    vector<int> b = {3, 1, 4, 2};
    cout << maxValidPairs(a, b) << endl;  // Output: 3
    return 0;
}
