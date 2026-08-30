class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        int minIndex = 0, maxIndex = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        
        int first = min(minIndex, maxIndex);
        int second = max(minIndex, maxIndex);
        
        // Scenario 1: Remove both from the front
        int front = second + 1;
        
        // Scenario 2: Remove both from the back
        int back = n - first;
        
        // Scenario 3: Remove one from the front and one from the back
        int both = (first + 1) + (n - second);
        
        return min({front, back, both});
    }
};