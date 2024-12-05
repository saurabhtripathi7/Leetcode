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
    int dfs(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right){
            return root->val;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Apply the operation based on the current node's value
        if (root->val == 2) { // OR operation
            return left | right;
        } else if (root->val == 3) { // AND operation
            return left & right;
        }
        return 0;
        
    }
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};
