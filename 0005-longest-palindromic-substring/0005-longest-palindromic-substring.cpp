class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int start = 0, maxLen = 0;
        
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; 
        };
        
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(i, i);
            int len2 = expandAroundCenter(i, i + 1);
            
            int currentMaxLen = max(len1, len2);
            
            if (currentMaxLen > maxLen) {
                maxLen = currentMaxLen;
                start = i - (maxLen - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};