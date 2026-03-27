class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(256, -1);
        int l = 0, ans = 0;
        for (int r = 0; r < s.size(); r++) {
            if (m[s[r]] >= l) l = m[s[r]] + 1;
            m[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};