#include <bits/stdc++.h>
using namespace std;

char kThCharacterOfDecryptedString(string s, long long k) {
    unordered_map<string, long long> freqMap;  // substring -> frequency
    vector<string> order;                       // to preserve insertion order
    int n = s.size();
    int i = 0;

    while (i < n) {
        // Read substring (letters)
        string sub = "";
        while (i < n && isalpha(s[i])) {
            sub += s[i];
            i++;
        }

        // Read frequency (digits)
        long long freq = 0;
        while (i < n && isdigit(s[i])) {
            freq = freq * 10 + (s[i] - '0');
            i++;
        }

        if (freqMap.find(sub) == freqMap.end()) order.push_back(sub);
        freqMap[sub] += freq;
    }

    // Find K-th character
    for (auto sub : order) {
        long long totalLen = sub.size() * freqMap[sub];
        if (k <= totalLen) {
            k--;  // convert to 0-based
            return sub[k % sub.size()];
        } else {
            k -= totalLen;
        }
    }

    return '#'; // K is out of bounds
}

int main() {
    string s = "a2b3cd3";
    long long K = 5;
    cout << kThCharacterOfDecryptedString(s, K) << endl; // Output: b
}
