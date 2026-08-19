class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMap;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Seats 1 and 10 do not affect the 4-person groups (2-5, 4-7, 6-9)
            if (col >= 2 && col <= 9) {
                reservedMap[row] |= (1 << col);
            }
        }
        
        // Rows with no reservations can seat 2 groups each
        int maxGroups = (n - reservedMap.size()) * 2;
        
        // Mask for seats 2,3,4,5 -> bits 2..5
        const int leftMask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);   // 60
        // Mask for seats 6,7,8,9 -> bits 6..9
        const int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);  // 960
        // Mask for seats 4,5,6,7 -> bits 4..7
        const int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); // 240
        
        for (const auto& [row, mask] : reservedMap) {
            bool leftPossible = !(mask & leftMask);
            bool rightPossible = !(mask & rightMask);
            
            if (leftPossible && rightPossible) {
                maxGroups += 2;
            } else if (leftPossible || rightPossible || !(mask & middleMask)) {
                maxGroups += 1;
            }
        }
        
        return maxGroups;
    }
};