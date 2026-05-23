class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        // Insert all stones into max heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); // Heaviest stone
            maxHeap.pop();

            int x = maxHeap.top(); // Second heaviest stone
            maxHeap.pop();

            // If stones are not equal
            if (y != x) {
                maxHeap.push(y - x);
            }
        }

        // Return remaining stone or 0
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};