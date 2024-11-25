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
    // Helper function for depth-first search
    bool dfs(TreeNode* node, int currentSum, int targetSum) {
        if (node == nullptr) return false; // Base case: null node
        
        currentSum += node->val; // Update the current sum
        
        // Check if leaf node and the sum matches the target
        if (currentSum == targetSum && node->left == nullptr && node->right == nullptr) {
            return true;
        }
        
        // Recursively check left and right subtrees
        return dfs(node->left, currentSum, targetSum) || dfs(node->right, currentSum, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum); // Start DFS with root node and initial sum as 0
    }
};

