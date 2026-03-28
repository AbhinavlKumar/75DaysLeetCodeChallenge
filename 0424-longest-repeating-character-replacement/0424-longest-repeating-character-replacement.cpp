class Solution {
public:
    int characterReplacement(string s, int k) {
      vector<int> freq(26, 0);
        int left = 0, maxCount = 0, res = 0;

        for (int right = 0; right < s.size(); right++) {
            maxCount = max(maxCount, ++freq[s[right] - 'A']);

            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;  
    }
};