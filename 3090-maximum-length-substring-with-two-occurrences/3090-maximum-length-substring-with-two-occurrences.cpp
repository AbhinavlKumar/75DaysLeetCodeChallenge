class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        std::vector<int> freq(26, 0);
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            freq[s[right] - 'a']++;

            // Shrink window from the left until the count is at most 2
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            // Update maximum valid substring length
            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};