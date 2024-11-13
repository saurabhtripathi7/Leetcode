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
public: // O(N) solution
    pair<bool, int> isBalancedFast(TreeNode* root){  
        //first-> isBalanced(true/false) ; second-> height

        if(!root) return {true, 0};

        pair<bool,int> leftAns = isBalancedFast(root->left);
        pair<bool,int> rightAns = isBalancedFast(root->right);
        bool diff = abs(leftAns.second - rightAns.second) <= 1;

        // build ans to return check, height
        pair<bool,int> ans;
        ans.second = max(leftAns.second, rightAns.second) +1; //stores height 
        //stores bool check
        if(leftAns.first == true && rightAns.first == true && diff == true) ans.first = true;
        else ans.first = false;
        
        return ans;

    }
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first; //as first contains the result t/f
    }
};
