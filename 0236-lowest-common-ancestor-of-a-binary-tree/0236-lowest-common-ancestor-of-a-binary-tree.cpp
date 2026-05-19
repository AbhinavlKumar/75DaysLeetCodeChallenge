/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or we found either p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        
        // Look for p and q in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If p and q are found in different subtrees, current root is the LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }
        
        // Otherwise, return the non-null value (either left or right)
        return left != nullptr ? left : right;
    }
};