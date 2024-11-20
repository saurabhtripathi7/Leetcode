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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        // preStart, preEnd
        return helper(preorder, 0, preorder.size() - 1,
                      // inStart, inEnd
                      inorder, 0, inorder.size() - 1,
                      inorderIndex); // map
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     unordered_map<int, int>& inorderIndex) {
                        // basecase: if no element to process, return null
                        if(preStart > preEnd || inStart > inEnd)
                            return NULL;

                        // first elem of preOrder is ROOT
                        TreeNode* root = new TreeNode(preorder[preStart]);
                        // find index of root in inorder and left subtree size
                        int pos = inorderIndex[root->val];
                        int leftSubtreeSize = pos - inStart; 

                        // rec call to build left subtree and right subtree
                        root->left = helper(preorder, preStart + 1, preStart+leftSubtreeSize,
                                            inorder, inStart, pos-1, inorderIndex);
                        
                        root->right = helper(preorder, preStart+leftSubtreeSize+1, preEnd,
                                            inorder, pos+1, inEnd, inorderIndex);
                        return root;
                     }
};
