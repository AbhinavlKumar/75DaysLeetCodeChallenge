class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int firstIndex = -1;
        int prevIndex = -1;
        int minDistance = INT_MAX;
        
        int currentIndex = 1;

        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;
            
            if ((curr->val > prev->val && curr->val > nextNode->val) || 
                (curr->val < prev->val && curr->val < nextNode->val)) {
                
                if (firstIndex == -1) {
                    firstIndex = currentIndex;
                    prevIndex = currentIndex;
                } else {
                    minDistance = min(minDistance, currentIndex - prevIndex);
                    prevIndex = currentIndex;
                }
            }
            
            prev = curr;
            curr = nextNode;
            currentIndex++;
        }

        if (firstIndex == -1 || minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = prevIndex - firstIndex;
        return {minDistance, maxDistance};
    }
};