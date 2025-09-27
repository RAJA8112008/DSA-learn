#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS to explore an island and record its shape
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n,
             vector<pair<int,int>>& shape, int baseI, int baseJ) {
        
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1)
            return;
        
        grid[i][j] = 0; // mark visited
        shape.push_back({i - baseI, j - baseJ}); // store relative coordinates
        
        // Explore 4 directions
        dfs(grid, i + 1, j, m, n, shape, baseI, baseJ);
        dfs(grid, i - 1, j, m, n, shape, baseI, baseJ);
        dfs(grid, i, j + 1, m, n, shape, baseI, baseJ);
        dfs(grid, i, j - 1, m, n, shape, baseI, baseJ);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int,int>>> unique; // to store distinct shapes
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    vector<pair<int,int>> shape;
                    dfs(grid, i, j, m, n, shape, i, j); // start DFS from this cell
                    unique.insert(shape); // insert island shape
                }
            }
        }
        return unique.size(); // number of distinct islands
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0},
        {0, 0, 1},
        {0, 0, 1}
    };
    
    Solution obj;
    cout << "Number of distinct islands: " << obj.countDistinctIslands(grid) << endl;
    return 0;
}
