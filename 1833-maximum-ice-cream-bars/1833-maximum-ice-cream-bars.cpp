class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost = 0;
        for (int c : costs) {
            if (c > max_cost) {
                max_cost = c;
            }
        }
        
        vector<int> freq(max_cost + 1, 0);
        for (int c : costs) {
            freq[c]++;
        }
        
        int ice_cream_bars = 0;
        for (int i = 1; i <= max_cost; ++i) {
            if (freq[i] == 0) continue;
            if (coins < i) break;
            
            int buy = min(freq[i], coins / i);
            ice_cream_bars += buy;
            coins -= buy * i;
        }
        
        return ice_cream_bars;
    }
};