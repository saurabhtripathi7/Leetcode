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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        int UB = INT_MAX;
        return build(preorder, i, UB);
    }
    TreeNode* build(vector<int>& preorder, int& i, int UB){
        // base case: if pre[i] is not smaller than UB or if pre gets exhasuted
        if(i == preorder.size() || preorder[i] > UB ) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i,root->val);
        root->right = build(preorder, i, UB);

        return root;
    }

};
