/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> rootIdx;
        for (int i = 0; i < inorder.size(); ++i) {
            rootIdx[inorder[i]] = i;
        }

        return helper(postorder, 0, postorder.size() - 1, inorder, 0,
                      inorder.size() - 1, rootIdx);
    }
    TreeNode* helper(vector<int>& postorder, int postStart, int postEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     unordered_map<int, int>& rootIdx) 
        {
            if(postStart > postEnd || inStart > inEnd) return NULL;

            TreeNode* root = new TreeNode(postorder[postEnd]);

            int pos = rootIdx[root->val];
            int leftSize = pos - inStart;

            root->left = helper(postorder, postStart, (postStart+leftSize-1),
                                inorder, inStart, (pos-1), rootIdx);
            root->right = helper(postorder, postStart + leftSize, (postEnd-1),
                                inorder, pos+1, inEnd, rootIdx); 
            return root;
        }
};
