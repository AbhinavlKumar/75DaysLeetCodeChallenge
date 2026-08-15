class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            totalXor ^= num;
            if (num > 0) {
                hasNonZero = true;
            }
        }

        // If the XOR of all elements is already non-zero, take the whole array.
        if (totalXor != 0) {
            return nums.size();
        }

        // If total XOR is 0 but at least one non-zero element exists, 
        // removing that single element makes the XOR non-zero.
        if (hasNonZero) {
            return nums.size() - 1;
        }

        // All elements are 0; impossible to get a non-zero XOR.
        return 0;
    }
};