#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, node, adj, vis)) 
                return true; // cycle found
        }
        else if (it != parent) 
            return true; // back edge => cycle
    }
    return false;
}

bool isTree(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);

    // Step 1: Check cycle
    if (dfs(0, -1, adj, vis)) return false;

    // Step 2: Check connectedness
    for (int i = 0; i < V; i++) {
        if (!vis[i]) return false;
    }

    // Step 3: Tree must have V-1 edges (can be checked outside)
    return true;
}

int main() {
    int V = 4; // vertices
    int E = 3; // edges
    vector<int> adj[V];

    // edges input
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    // Edge condition
    if (E != V - 1) {
        cout << "Not a Tree";
        return 0;
    }

    if (isTree(V, adj))
        cout << "Graph is a Tree";
    else
        cout << "Graph is NOT a Tree";

    return 0;
}
