class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (int pile : piles) {
            high = max(high, pile);
        }

        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canEatAll(piles, mid, h)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

private:
    bool canEatAll(vector<int>& piles, int speed, int h) {
        long long actualHours = 0;
        for (int pile : piles) {
            // Ceiling division: (pile + speed - 1) / speed
            actualHours += (pile + speed - 1) / speed;
        }
        return actualHours <= h;
        
    }
};