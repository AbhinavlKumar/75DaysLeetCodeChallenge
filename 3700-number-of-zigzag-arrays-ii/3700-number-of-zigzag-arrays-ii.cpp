class Solution {
private:
    const int MOD = 1e9 + 7;
    int m;

    // Standard Matrix Multiplication: A * B
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        vector<vector<long long>> C(m, vector<long long>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < m; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < m; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Fast Matrix Exponentiation: Base^p
    vector<vector<long long>> power(vector<vector<long long>> base, long long p) {
        vector<vector<long long>> res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; ++i) res[i][i] = 1; // Identity matrix

        while (p > 0) {
            if (p & 1) res = multiply(res, base);
            base = multiply(base, base);
            p >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        m = r - l + 1;
        if (n == 1) return m;
        if (n == 2) return (1LL * m * (m - 1)) % MOD;

        // U[i][j] = 1 if j > i (Strictly Increasing step)
        // L[i][j] = 1 if j < i (Strictly Decreasing step)
        vector<vector<long long>> U(m, vector<long long>(m, 0));
        vector<vector<long long>> L(m, vector<long long>(m, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j > i) U[i][j] = 1;
                if (j < i) L[i][j] = 1;
            }
        }

        // Alternating steps means a full cycle is U * L
        vector<vector<long long>> UL = multiply(U, L);

        // We need total n-1 transitions. 
        // We raise the alternating transition matrix to (n-1) / 2
        long long steps = (n - 1) / 2;
        vector<vector<long long>> P = power(UL, steps);

        // If (n-1) is odd, we have an extra single transition remaining
        if ((n - 1) & 1) {
            P = multiply(L, P);
        }

        // Sum up all elements in the final transition matrix
        long long total_ways = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                total_ways = (total_ways + P[i][j]) % MOD;
            }
        }

        // Multiply by 2 to account for arrays starting with an increasing vs decreasing step
        return (total_ways * 2) % MOD;
    }
};