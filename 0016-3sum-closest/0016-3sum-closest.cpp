class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 1. Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        // Initialize closestSum with the sum of the first three elements
        long closestSum = nums[0] + nums[1] + nums[2];
        
        // 2. Iterate through the array, fixing one number at a time
        for (int i = 0; i < n - 2; ++i) {
            // Optimization: Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            // 3. Use two pointers to find the best pair for the fixed nums[i]
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If we found the exact target, return it immediately
                if (currentSum == target) {
                    return currentSum;
                }
                
                // 4. Update closestSum if the currentSum is nearer to the target
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // 5. Move pointers based on how currentSum compares to target
                if (currentSum < target) {
                    left++; // Need a larger sum
                } else {
                    right--; // Need a smaller sum
                }
            }
        }
        
        return (int)closestSum;
    }
};