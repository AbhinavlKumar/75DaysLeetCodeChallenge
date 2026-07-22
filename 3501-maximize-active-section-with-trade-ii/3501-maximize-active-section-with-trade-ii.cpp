struct Group {
    int start;
    int length;
};

class SparseTable {
public:
    SparseTable(const vector<int>& nums) : n(nums.size()), st(32 - __builtin_clz(max((int)nums.size(), 1)) + 1, vector<int>(nums.size() + 1)) {
        for (int i = 0; i < n; ++i) st[0][i] = nums[i];
        for (int i = 1; (1 << i) <= n; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        if (l > r) return 0;
        int i = 31 - __builtin_clz(r - l + 1);
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }

private:
    int n;
    vector<vector<int>> st;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().length++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
            }
            zeroGroupIndex[i] = (int)zeroGroups.size() - 1;
        }

        if (zeroGroups.empty()) return vector<int>(queries.size(), ones);

        vector<int> zeroMergeLengths;
        for (size_t i = 0; i + 1 < zeroGroups.size(); ++i) {
            zeroMergeLengths.push_back(zeroGroups[i].length + zeroGroups[i + 1].length);
        }

        SparseTable st(zeroMergeLengths);
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];

            int left = zeroGroupIndex[l] == -1 ? -1 : (zeroGroups[zeroGroupIndex[l]].length - (l - zeroGroups[zeroGroupIndex[l]].start));
            int right = zeroGroupIndex[r] == -1 ? -1 : (r - zeroGroups[zeroGroupIndex[r]].start + 1);

            int startAdjacentGroupIndex = zeroGroupIndex[l] + 1;
            int endAdjacentGroupIndex = (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1) - 1;

            int activeSections = ones;

            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {
                activeSections = max(activeSections, ones + left + right);
            } else if (startAdjacentGroupIndex <= endAdjacentGroupIndex) {
                activeSections = max(activeSections, ones + st.query(startAdjacentGroupIndex, endAdjacentGroupIndex));
            }

            if (s[l] == '0' && zeroGroupIndex[l] + 1 <= (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1)) {
                activeSections = max(activeSections, ones + left + zeroGroups[zeroGroupIndex[l] + 1].length);
            }

            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {
                activeSections = max(activeSections, ones + right + zeroGroups[zeroGroupIndex[r] - 1].length);
            }

            ans.push_back(activeSections);
        }

        return ans;
    }
};