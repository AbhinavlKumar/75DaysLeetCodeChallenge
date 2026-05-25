class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Array to store the frequency of each uppercase letter task
        vector<int> freq(26, 0);
        int max_freq = 0;
        
        // Calculate frequencies and find the maximum frequency
        for (char task : tasks) {
            freq[task - 'A']++;
            max_freq = max(max_freq, freq[task - 'A']);
        }
        
        // Count how many tasks have that maximum frequency
        int max_count = 0;
        for (int f : freq) {
            if (f == max_freq) {
                max_count++;
            }
        }
        
        // Calculate the minimum intervals based on the most frequent tasks
        int intervals = (max_freq - 1) * (n + 1) + max_count;
        
        // The result is the maximum of the calculated intervals or the total number of tasks 
        // (in case there are enough different tasks to fill all idle slots naturally)
        return max((int)tasks.size(), intervals);
        
    }
};