class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < total; i++) {
            int newIndex = (i + k) % total;
            result[newIndex / n][newIndex % n] = grid[i / n][i % n];
        }
        
        return result;
    }
};