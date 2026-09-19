class Solution {
public:
    TreeNode* helper(TreeNode* root, int limit, int sum = 0){
        if(!root) return NULL;

        if(!root -> left && !root -> right){
            return root -> val + sum < limit ? NULL : root;
        }

        root->left = helper(root->left, limit, sum + root->val);
        root->right = helper(root->right, limit, sum + root->val);

        return (!root->left && !root->right) ? NULL : root;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return helper(root, limit, 0);
    }
};