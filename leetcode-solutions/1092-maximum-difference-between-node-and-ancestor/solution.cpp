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
    int maxDiff(TreeNode* root, int mini, int maxi){
        if(!root) return abs(maxi-mini);

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        int leftAns = maxDiff(root->left, mini, maxi);
        int rightAns = maxDiff(root->right, mini, maxi);

        return max(leftAns, rightAns);

    }
    int maxAncestorDiff(TreeNode* root) {
        return maxDiff(root, root->val, root->val);
    }
};
