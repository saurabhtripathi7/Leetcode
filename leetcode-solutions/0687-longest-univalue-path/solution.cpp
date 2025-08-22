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
    int ans;
    int dfs(TreeNode* node, int parent){
        if(!node) return 0;

        int left = dfs(node->left, node->val);
        int right = dfs(node->right, node->val);
        
        ans = max(ans, left + right); //ans from both sides

        return node->val == parent ? max(left, right) + 1 : 0;


    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root, -1);
        return ans;
    }
};
