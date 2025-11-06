#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;          // stores BFS traversal
        vector<int> visited(V, 0); // track visited nodes

        queue<int> q;
        q.push(0);                // start from node 0
        visited[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            // traverse all adjacent nodes
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};



int main() {
    int V = 5; // number of vertices
    vector<int> adj[V];

    // Example graph
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    Solution obj;
    vector<int> result = obj.bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (auto x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
