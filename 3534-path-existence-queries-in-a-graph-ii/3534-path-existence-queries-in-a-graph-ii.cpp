class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            if (nums[i] != nums[j]) return nums[i] < nums[j];
            return i < j;
        });

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[indices[i]] = i;
        }

        int LOG = 18;
        vector<vector<int>> up(n, vector<int>(LOG));
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && nums[indices[r]] - nums[indices[l]] <= maxDiff) {
                r++;
            }
            up[l][0] = r - 1;
        }

        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int p1 = pos[u], p2 = pos[v];
            if (p1 > p2) swap(p1, p2);

            int jumps = 0;
            int curr = p1;
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[curr][j] < p2) {
                    jumps += (1 << j);
                    curr = up[curr][j];
                }
            }

            if (up[curr][0] >= p2) {
                ans.push_back(jumps + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};