class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1}; // 1-based index
            }
            else if (sum < target) {
                left++;  // need bigger sum
            }
            else {
                right--; // need smaller sum
            }
        }

        return {}; // won't reach here (guaranteed solution)
    }
};