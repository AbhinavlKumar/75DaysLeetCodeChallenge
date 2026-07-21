class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initialOnes = 0;
        for (char c : s) {
            if (c == '1') {
                initialOnes++;
            }
        }

        string t = "1" + s + "1";
        vector<int> zeroSegmentLengths;
        int i = 0, n = t.length();

        while (i < n) {
            if (t[i] == '0') {
                int len = 0;
                while (i < n && t[i] == '0') {
                    len++;
                    i++;
                }
                zeroSegmentLengths.push_back(len);
            } else {
                i++;
            }
        }

        int maxDelta = 0;
        for (size_t k = 1; k < zeroSegmentLengths.size(); ++k) {
            maxDelta = max(maxDelta, zeroSegmentLengths[k - 1] + zeroSegmentLengths[k]);
        }

        return initialOnes + maxDelta;
    }
};