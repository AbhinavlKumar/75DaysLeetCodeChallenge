class Solution {
    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    // Counts distinct multiples <= m made from any coin in coins
    long long countMultiples(long long m, const std::vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        // Iterate over all non-empty subsets
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long currentLcm = 1;
            int bitCount = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bitCount++;
                    currentLcm = lcm(currentLcm, coins[i]);
                    if (currentLcm > m) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (!overflow) {
                if (bitCount % 2 == 1) {
                    total += m / currentLcm;
                } else {
                    total -= m / currentLcm;
                }
            }
        }
        return total;
    }

public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        long long low = 1;
        long long minCoin = *std::min_element(coins.begin(), coins.end());
        long long high = minCoin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};