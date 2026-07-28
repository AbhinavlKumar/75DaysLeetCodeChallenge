class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string half = s.substr(0, n / 2);
        sort(half.begin(), half.end());
        
        string res = half;
        if (n % 2 != 0) {
            res += s[n / 2];
        }
        reverse(half.begin(), half.end());
        res += half;
        
        return res;
    }
};