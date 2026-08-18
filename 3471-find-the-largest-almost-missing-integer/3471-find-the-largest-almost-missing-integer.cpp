class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k equals array length -> only 1 subarray exists
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }
        
        // Case 2: k == 1 -> find max element that appears exactly once in nums
        if (k == 1) {
            std::unordered_map<int, int> freq;
            for (int x : nums) freq[x]++;
            
            int ans = -1;
            for (auto [x, count] : freq) {
                if (count == 1) {
                    ans = std::max(ans, x);
                }
            }
            return ans;
        }
        
        // Case 3: 1 < k < n -> only the first and last elements can belong to exactly one subarray
        std::unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        
        int ans = -1;
        if (freq[nums[0]] == 1) ans = std::max(ans, nums[0]);
        if (freq[nums[n - 1]] == 1) ans = std::max(ans, nums[n - 1]);
        
        return ans;
    }
};