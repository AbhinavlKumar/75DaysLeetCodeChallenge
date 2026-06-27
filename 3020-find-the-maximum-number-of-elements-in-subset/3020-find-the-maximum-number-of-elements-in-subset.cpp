class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        int max_len = 0;
        if (counts.count(1)) {
            int ones = counts[1];
            max_len = (ones % 2 == 0) ? ones - 1 : ones;
        }
        
        for (auto& [val, count] : counts) {
            if (val == 1) continue;
            
            long long current = val;
            int current_len = 0;
            
            while (counts.count(current) && counts[current] >= 2) {
                current_len += 2;
                current = current * current;
            }
            
            if (counts.count(current) && counts[current] >= 1) {
                current_len += 1;
            } else {
                current_len -= 1;
            }
            
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};