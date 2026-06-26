class FenwickTree {
    vector<int> tree;
    int size;
public:
    FenwickTree(int n) : size(n) {
        tree.assign(n + 1, 0);
    }
    void update(int i, int delta) {
        for (; i <= size; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }
        
        vector<int> coords = pref;
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
        
        auto get_rank = [&](int val) {
            return lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
        };
        
        FenwickTree bit(coords.size());
        long long result = 0;
        
        for (int i = 0; i <= n; ++i) {
            int rank = get_rank(pref[i]);
            result += bit.query(rank - 1);
            bit.update(rank, 1);
        }
        
        return result;
    }
};