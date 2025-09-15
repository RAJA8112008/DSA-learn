#include <bits/stdc++.h>
using namespace std;

int primsMST(int V, vector<vector<pair<int,int>>> &adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> visited(V, 0);

    int sum = 0;
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        auto [wt, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;
        visited[node] = 1;
        sum += wt;

        for (auto [adjNode, edgeWt] : adj[node]) {
            if (!visited[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return sum;
}





int main() {
    int V = 4;
    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,1});
    adj[1].push_back({0,1});

    adj[0].push_back({2,2});
    adj[2].push_back({0,2});

    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    adj[1].push_back({3,4});
    adj[3].push_back({1,4});

    adj[2].push_back({3,5});
    adj[3].push_back({2,5});

    cout << "Total weight of MST: " << primsMST(V, adj) << endl;
    return 0;
}
