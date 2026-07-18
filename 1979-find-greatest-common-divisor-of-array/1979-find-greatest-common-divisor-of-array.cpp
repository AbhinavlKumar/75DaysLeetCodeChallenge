class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];
        for (int num : nums) {
            if (num < mn) mn = num;
            if (num > mx) mx = num;
        }
        return std::gcd(mn, mx);
    }
};