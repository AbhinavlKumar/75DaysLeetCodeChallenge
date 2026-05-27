class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScores(n + 1, 0);

        for(const auto& relation : trust) {
            trustScores[relation[0]]--;
            trustScores[relation[1]]++;
        }
        
        for(int i = 1; i<= n; ++i) {
            if (trustScores[i] == n -1) {
                return i;
            }
        }
        return -1;
    }
};