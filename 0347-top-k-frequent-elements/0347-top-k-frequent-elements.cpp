#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Bucket sort
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &p : freq) {
            bucket[p.second].push_back(p.first);
        }

        // Get top k elements
        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};