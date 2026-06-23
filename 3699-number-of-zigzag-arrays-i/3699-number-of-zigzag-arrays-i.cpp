class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        long long MOD = 1e9 + 7;

        vector<long long> dp0(m, 1);
        vector<long long> dp1(m, 1);

        for (int i = 2; i <= n; ++i) {
            vector<long long> next_dp0(m, 0);
            vector<long long> next_dp1(m, 0);

            long long sum0 = 0;
            for (int j = 0; j < m; ++j) {
                next_dp1[j] = sum0;
                sum0 = (sum0 + dp0[j]) % MOD;
            }

            long long sum1 = 0;
            for (int j = m - 1; j >= 0; --j) {
                next_dp0[j] = sum1;
                sum1 = (sum1 + dp1[j]) % MOD;
            }

            dp0 = move(next_dp0);
            dp1 = move(next_dp1);
        }

        long long ans = 0;
        for (int j = 0; j < m; ++j) {
            ans = (ans + dp0[j] + dp1[j]) % MOD;
        }

        return ans;
    }
};