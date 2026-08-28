class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if a palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        int m = n / 2;

        // Characters available for the first half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        // Build complete palindrome
        auto build = [&](const string& half) {
            string ans = half;

            if (n % 2) {
                ans += mid;
            }

            for (int i = m - 1; i >= 0; i--) {
                ans += half[i];
            }

            return ans;
        };

        string targetHalf = target.substr(0, m);

        // Try making first half equal to target's first half
        vector<int> rem = halfCnt;
        string half;
        bool possible = true;

        for (int i = 0; i < m; i++) {
            int c = targetHalf[i] - 'a';

            if (rem[c] == 0) {
                possible = false;
                break;
            }

            half += targetHalf[i];
            rem[c]--;
        }

        // If the first half can be equal,
        // check whether the complete palindrome is greater.
        if (possible) {
            string ans = build(half);

            if (ans > target) {
                return ans;
            }
        }

        // Find the rightmost position where we can
        // choose a character greater than target.
        for (int pos = m - 1; pos >= 0; pos--) {

            rem = halfCnt;
            string prefix;
            bool ok = true;

            // Match target before pos
            for (int i = 0; i < pos; i++) {
                int c = targetHalf[i] - 'a';

                if (rem[c] == 0) {
                    ok = false;
                    break;
                }

                prefix += targetHalf[i];
                rem[c]--;
            }

            if (!ok) {
                continue;
            }

            // Choose smallest character greater than target[pos]
            for (int c = targetHalf[pos] - 'a' + 1; c < 26; c++) {

                if (rem[c] == 0) {
                    continue;
                }

                string newHalf = prefix;
                newHalf += char('a' + c);

                rem[c]--;

                // Fill the remaining positions
                // with the smallest characters.
                for (int x = 0; x < 26; x++) {
                    newHalf += string(rem[x], char('a' + x));
                }

                string ans = build(newHalf);

                if (ans > target) {
                    return ans;
                }

                rem[c]++;
            }
        }

        return "";
    }
};