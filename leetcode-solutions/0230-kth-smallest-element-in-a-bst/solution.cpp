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
    void inorderTraversal(TreeNode* root, int& k, int& result) {
        if (!root)
            return;

        // Traverse the left subtree
        inorderTraversal(root->left, k, result);

        // Decrement k (current node is the k-th element if k == 1)
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }

        // Traverse the right subtree
        inorderTraversal(root->right, k, result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = -1; // Default value if k is invalid
        inorderTraversal(root, k, result);
        return result;
    }
};
