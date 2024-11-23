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
    // Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root; // Base case: tree is empty

        // Traverse the tree to find the node to delete
        if (key < root->val) {
            root->left =
                deleteNode(root->left, key); // Search in the left subtree
        } else if (key > root->val) {
            root->right =
                deleteNode(root->right, key); // Search in the right subtree
        } else {
            // Node to delete is found
            // Case 1: No children or only one child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root; // Free memory
                return temp; // Return the child (or nullptr)
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root; // Free memory
                return temp; // Return the child
            }

            // Case 2: Node has two children
            TreeNode* temp = findMin(root->right); // Find the inorder successor
            root->val = temp->val; // Replace value with successor's value
            root->right =
                deleteNode(root->right, temp->val); // Delete the successor
        }

        return root; // Return the modified tree
    }
};
