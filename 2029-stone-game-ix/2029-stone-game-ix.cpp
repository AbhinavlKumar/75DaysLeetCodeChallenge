class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);
        for (int x : stones) {
            cnt[x % 3]++;
        }
        
        // If the count of remainder 0 stones is even:
        if (cnt[0] % 2 == 0) {
            return cnt[1] >= 1 && cnt[2] >= 1;
        }
        
        // If the count of remainder 0 stones is odd:
        return abs(cnt[1] - cnt[2]) > 2;
    }
};