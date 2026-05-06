class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX;
        int left = 0;
        long long currentSum = 0;

        for (int right = 0; right < n; right++) {
            // Expand the window by adding the current element
            currentSum += nums[right];

            // Shrink the window from the left as long as the sum is >= target
            while (currentSum >= target) {
                minLength = min(minLength, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
        }

        // If minLength was never updated, no such subarray exists
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};