#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, vector<char>> adj;
    unordered_map<char, int> indegree;

    // Initialize indegree for all unique characters
    for (auto &word : words) {
        for (auto c : word) {
            indegree[c] = 0;
        }
    }

    // Build graph
    for (int i = 0; i < words.size() - 1; i++) {
        string w1 = words[i];
        string w2 = words[i + 1];

        // Invalid case: prefix issue
        if (w1.size() > w2.size() && w1.find(w2) == 0) {
            return "";
        }

        int len = min(w1.size(), w2.size());
        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                adj[w1[j]].push_back(w2[j]);
                indegree[w2[j]]++;
                break; // only first differing char matters
            }
        }
    }

    // Topological Sort (BFS - Kahn’s Algorithm)
    queue<char> q;
    for (auto &p : indegree) {
        if (p.second == 0) q.push(p.first);
    }

    string result = "";
    while (!q.empty()) {
        char node = q.front(); q.pop();
        result += node;

        for (char nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) q.push(nbr);
        }
    }

    // If cycle exists (not all processed)
    if (result.size() != indegree.size()) return "";

    return result;
}

// Example usage
int main() {

    
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    string order = alienOrder(words);
    if(order.empty()) cout << "false\n";
    else cout << order << endl;
    return 0;
}
