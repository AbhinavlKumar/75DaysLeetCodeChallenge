class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        int half = n / 2;
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        vector<int> half_count(26, 0);
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
            if (count[i] % 2 == 1) {
                mid_char = 'a' + i;
            }
        }

        auto countPermutations = [&](vector<int>& freq, long long limit) -> long long {
            int total = 0;
            int max_idx = -1;
            int max_c = 0;

            for (int i = 0; i < 26; ++i) {
                total += freq[i];
                if (freq[i] > max_c) {
                    max_c = freq[i];
                    max_idx = i;
                }
            }

            if (total == 0) return 1;

            long long ans = 1;
            int rem = total;

            for (int i = 0; i < 26; ++i) {
                if (i == max_idx || freq[i] == 0) continue;
                for (int j = 1; j <= freq[i]; ++j) {
                    ans = (ans * rem) / j;
                    rem--;
                    if (ans > limit) return limit + 1;
                }
            }
            return ans;
        };

        string prefix = "";
        long long current_k = k;

        if (countPermutations(half_count, current_k) < current_k) {
            return "";
        }

        for (int i = 0; i < half; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_count[c] > 0) {
                    half_count[c]--;
                    long long cnt = countPermutations(half_count, current_k);
                    if (cnt >= current_k) {
                        prefix += (char)('a' + c);
                        break;
                    } else {
                        current_k -= cnt;
                        half_count[c]++;
                    }
                }
            }
        }

        string suffix = prefix;
        reverse(suffix.begin(), suffix.end());

        if (n % 2 != 0) {
            return prefix + mid_char + suffix;
        }
        return prefix + suffix;
    }
};