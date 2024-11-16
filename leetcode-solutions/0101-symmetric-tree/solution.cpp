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
    bool dfs(TreeNode* first, TreeNode* second){
        if(first == NULL && second == NULL) return true;
        if(first == NULL || second == NULL) return false;
        
        bool op1 = dfs(first->left, second->right);
        bool op2 = dfs(first->right, second->left);
        bool op3 = first->val == second->val;

        return op1 && op2 && op3;
         
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root->left, root->right);
    }
};
