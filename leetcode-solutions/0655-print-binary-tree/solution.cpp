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
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int leftAns = height(root->left);
        int rightAns = height(root->right);

        return max(leftAns, rightAns) + 1;
    }

    void dfs(TreeNode* root, vector<vector<string>>& res, int level, int r, int c) {
        if (!root) return;

        if (root->left) {
            int leftCol = c - pow(2, level - r - 1);
            res[r + 1][leftCol] = to_string(root->left->val);
            dfs(root->left, res, level, r + 1, leftCol);
        }
        if (root->right) {
            int rightCol = c + pow(2, level - r - 1);
            res[r + 1][rightCol] = to_string(root->right->val);
            dfs(root->right, res, level, r + 1, rightCol);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int level = height(root) - 1;

        int m = level + 1;
        int n = pow(2, level+1) -1;
        vector<vector<string>>res(m, vector<string>(n));

        res[0][(n-1)/2] =to_string(root->val);
        
        dfs(root, res, level, 0, (n-1)/2);

        return res;

    }
};
