class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> total_count(26, 0);
        for (char ch : s) {
            total_count[ch - 'a']++;
        }

        for (int i = n - 1; i >= 0; --i) {
            vector<int> count = total_count;
            bool can_match_prefix = true;

            for (int j = 0; j < i; ++j) {
                int idx = target[j] - 'a';
                if (--count[idx] < 0) {
                    can_match_prefix = false;
                    break;
                }
            }

            if (!can_match_prefix) continue;

            int branch_char = -1;
            for (int c = (target[i] - 'a') + 1; c < 26; ++c) {
                if (count[c] > 0) {
                    branch_char = c;
                    break;
                }
            }

            if (branch_char != -1) {
                count[branch_char]--;
                string ans = target.substr(0, i);
                ans += (char)('a' + branch_char);

                for (int c = 0; c < 26; ++c) {
                    ans.append(count[c], (char)('a' + c));
                }
                return ans;
            }
        }

        return "";
    }
};