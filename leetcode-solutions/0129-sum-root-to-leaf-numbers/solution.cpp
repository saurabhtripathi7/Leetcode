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
    void dfs(TreeNode* root, int currSum, int& totalSum){
        if(!root) return;

        currSum = currSum*10+root->val;

        if(root->left == nullptr && root->right == nullptr){
            totalSum += currSum;
        }
        else{
            dfs(root->left, currSum, totalSum);
            dfs(root->right, currSum, totalSum);
        }
    }
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        dfs(root, 0, totalSum);
        return totalSum;
    }
};
