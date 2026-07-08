class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        vector<int> nz_val, nz_idx;
        vector<long long> pref_sum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pref_sum[i + 1] = pref_sum[i] + (s[i] - '0');
            if (s[i] != '0') {
                nz_val.push_back(s[i] - '0');
                nz_idx.push_back(i);
            }
        }

        int nz_sz = nz_val.size();
        if (nz_sz == 0) {
            return vector<int>(queries.size(), 0);
        }

        vector<long long> P(nz_sz + 1, 0);
        vector<long long> pow10(nz_sz + 1, 1);

        for (int i = 0; i < nz_sz; i++) {
            P[i + 1] = (P[i] * 10 + nz_val[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            auto it1 = lower_bound(nz_idx.begin(), nz_idx.end(), l);
            auto it2 = upper_bound(nz_idx.begin(), nz_idx.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = distance(nz_idx.begin(), it1);
            int R = distance(nz_idx.begin(), it2) - 1;
            int count = R - L + 1;

            long long x = (P[R + 1] - (P[L] * pow10[count]) % MOD + MOD) % MOD;
            long long sm = pref_sum[r + 1] - pref_sum[l];

            ans.push_back((x * sm) % MOD);
        }

        return ans;
    }
};