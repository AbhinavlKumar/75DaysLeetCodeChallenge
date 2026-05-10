class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            // Use 0 height at the end to flush the remaining bars in the stack
            int currentHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // If stack is empty, the bar 'height' was the smallest seen so far
                // Width is determined by the current index 'i' and the new top of stack
                int width = st.empty() ? i : i - st.top() - 1;
                
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        return maxArea;
        
    }
};