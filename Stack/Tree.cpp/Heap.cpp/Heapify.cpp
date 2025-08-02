#include <iostream>
#include <queue>
#include <string>
using namespace std;

class temp {
public:
    char ch;
    int count;

    // ✅ Fixed constructor (renamed parameter to avoid conflict)
    temp(char c, int cnt) {
        ch = c;
        count = cnt;
    }
};

class compare {
public:
    bool operator()(temp a, temp b) {
        return a.count < b.count;  // Max heap: highest count comes first
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        // Count frequencies
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        // Check if reorganization is possible
        for (int i = 0; i < 26; i++) {
            if (freq[i] > (s.length() + 1) / 2) {
                return "";
            }
        }

        // Build max heap with custom comparator
        priority_queue<temp, vector<temp>, compare> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(temp(i + 'a', freq[i]));
            }
        }

        string result = "";

        // Main loop to build output string
        while (pq.size() >= 2) {
            temp first = pq.top(); pq.pop();
            temp second = pq.top(); pq.pop();

            result += first.ch;
            result += second.ch;

            first.count--;
            second.count--;

            if (first.count > 0) {
                pq.push(first);
            }
            if (second.count > 0) {
                pq.push(second);
            }
        }

        // Handle last remaining character (if any)
        if (!pq.empty()) {
            if (pq.top().count > 1) return "";
            result += pq.top().ch;
        }

        return result;
    }
};

// Test code
int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = sol.reorganizeString(s);
    if (result == "") {
        cout << "Not possible to rearrange without adjacent same characters." << endl;
    } else {
        cout << "Reorganized string: " << result << endl;
    }

    return 0;
}
