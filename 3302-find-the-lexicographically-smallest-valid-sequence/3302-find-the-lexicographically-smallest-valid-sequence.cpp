class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> last(m + 1, -1);
        last[m] = n;
        
        for (int j = m - 1, i = n - 1; j >= 0; j--) {
            while (i >= 0 && word1[i] != word2[j]) {
                i--;
            }
            last[j] = i;
            if (i >= 0) {
                i--;
            }
        }

        vector<int> ans;
        bool changed = false;
        int i = 0;

        for (int j = 0; j < m; j++) {
            while (i < n) {
                if (word1[i] == word2[j]) {
                    if (!changed || last[j + 1] > i) {
                        ans.push_back(i);
                        i++;
                        break;
                    }
                } else {
                    if (!changed && last[j + 1] > i) {
                        changed = true;
                        ans.push_back(i);
                        i++;
                        break;
                    }
                }
                i++;
            }
            if (ans.size() != j + 1) {
                return {};
            }
        }

        return ans;
    }
};