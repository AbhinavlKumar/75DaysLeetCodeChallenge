class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k_limit;

public:
    KthLargest(int k, vector<int>& nums) {
        k_limit = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k_limit) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */