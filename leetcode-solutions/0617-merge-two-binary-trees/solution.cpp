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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2; // If the first tree node is null, return the second tree node
        if (!root2) return root1; // If the second tree node is null, return the first tree node

        // Create a new node with the sum of the values of the two nodes
        TreeNode* newNode = new TreeNode(root1->val + root2->val);
        // Recursively merge the left and right subtrees
        newNode->left = mergeTrees(root1->left, root2->left);
        newNode->right = mergeTrees(root1->right, root2->right);

        return newNode; // Return the merged tree
    }
};
