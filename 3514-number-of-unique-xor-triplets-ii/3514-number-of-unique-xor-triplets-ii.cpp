class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> unique_set(nums.begin(), nums.end());
        vector<int> u(unique_set.begin(), unique_set.end());
        
        vector<bool> pair_xor(2048, false);
        for (int a : u) {
            for (int b : u) {
                pair_xor[a ^ b] = true;
            }
        }
        
        vector<bool> triplet_xor(2048, false);
        for (int px = 0; px < 2048; ++px) {
            if (!pair_xor[px]) continue;
            for (int c : u) {
                triplet_xor[px ^ c] = true;
            }
        }
        
        int count = 0;
        for (bool present : triplet_xor) {
            if (present) {
                count++;
            }
        }
        
        return count;
    }
};