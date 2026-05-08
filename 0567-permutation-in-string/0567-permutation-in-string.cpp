class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // If s1 is longer than s2, s2 cannot contain a permutation of s1
        if (n1 > n2) return false;

        // Frequency arrays for 'a'-'z'
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // Initialize the first window
        for (int i = 0; i < n1; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Slide the window across s2
        for (int i = 0; i < n2 - n1; i++) {
            if (s1Count == s2Count) return true;

            // Move window: remove the leftmost character and add the next character on the right
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + n1] - 'a']++;
        }

        // Check the last window
        return s1Count == s2Count;
    }
};