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
    int Height(TreeNode* root) {
        if(!root) return 0;

        int LH = Height(root->left);
        int RH = Height(root->right);

        return 1+max(LH, RH);
    }        

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int LH = Height(root->left);
        int RH = Height(root->right);

        if(abs(RH-LH) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(left == false || right == false) return false;        
        
        return true;

    }
};
