class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // Run DFS from the vertical borders (left -> Pacific, right -> Atlantic)
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0); 
            dfs(heights, atlantic, i, n - 1); 
        }
        
        // Run DFS from the horizontal borders (top -> Pacific, bottom -> Atlantic)
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j); 
            dfs(heights, atlantic, m - 1, j); 
        }
        
        // Collect cells that can reach both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        int m = heights.size();
        int n = heights[0].size();
        
        // Directions: Up, Down, Left, Right
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            
            // Check boundaries
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                // Because we are flowing backwards from the ocean to the island, 
                // the new cell's height must be greater than or equal to the current cell's height
                if (!visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    dfs(heights, visited, nr, nc);
                }
            }
        }
    }
};