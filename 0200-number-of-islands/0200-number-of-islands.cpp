class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int num_islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find a '1', it's a new island
                if (grid[i][j] == '1') {
                    ++num_islands;
                    // Run DFS to mark all connected lands as visited
                    dfs(grid, i, j, m, n);
                }
            }
        }
        
        return num_islands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        // Boundary check and check if we are on water ('0')
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current land as visited by changing it to '0'
        grid[i][j] = '0';
        
        // Explore all 4 adjacent directions (up, down, left, right)
        dfs(grid, i - 1, j, m, n); // Up
        dfs(grid, i + 1, j, m, n); // Down
        dfs(grid, i, j - 1, m, n); // Left
        dfs(grid, i, j + 1, m, n); // Right
        
    }
};