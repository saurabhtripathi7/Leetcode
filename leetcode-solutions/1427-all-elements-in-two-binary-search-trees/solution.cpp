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
    void helper(TreeNode* root, vector<int>& ans){
        if(!root) return;

        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);

    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        
        helper(root1, ans1);
        helper(root2, ans2);
        
        ans1.insert(ans1.end(), ans2.begin(), ans2.end());
        sort(ans1.begin(), ans1.end());
        return ans1;
    }
};
