class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            count[nums[right]]++;
            
            while (count[nums[right]] > k) {
                count[nums[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};