/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to perform the recursion
    void traverse(TreeNode* node, vector<int>& result) {
        // Base case: if the current node is null, stop and return
        if (node == nullptr) {
            return;
        }
        
        // 1. Visit the Root: Add the current node's value to the result list
        result.push_back(node->val);
        
        // 2. Traverse Left: Recursively call the function for the left child
        traverse(node->left, result);
        
        // 3. Traverse Right: Recursively call the function for the right child
        traverse(node->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; // This will store our final traversal sequence
        traverse(root, result); // Start the recursion from the root
        return result;
    }
};