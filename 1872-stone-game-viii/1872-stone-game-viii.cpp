class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        for (int i = 1; i < n; ++i) {
            stones[i] += stones[i - 1];
        }
        
        int dp = stones[n - 1];
        
        for (int i = n - 2; i >= 1; --i) {
            dp = std::max(dp, stones[i] - dp);
        }
        
        return dp;
    }
};