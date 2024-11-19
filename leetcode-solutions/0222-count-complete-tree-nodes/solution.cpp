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
    // Function to count the nodes in a complete binary tree
    int countNodes(TreeNode* root) {
        // Base case: if the tree is empty, return 0
        if (root == NULL) return 0;
        
        // Calculate the height of the left and right subtrees
        int lh = findHeightLeft(root);  // Left subtree height
        int rh = findHeightRight(root); // Right subtree height
        
        // If both heights are the same, the tree is complete (perfectly filled)
        // We can directly calculate the total number of nodes as 2^height - 1
        if (lh == rh) return (1 << lh) - 1; // (1 << lh) is the same as 2^lh
        
        // If the heights are different, recursively count nodes in both subtrees
        return 1 + countNodes(root->left) + countNodes(root->right); // Add 1 for the root node
    }

    // Function to calculate the height of the left subtree
    int findHeightLeft(TreeNode* node) {
        int hgt = 0; // Initialize the height counter
        while (node) {
            hgt++;        // Increase height for each level down the left subtree
            node = node->left; // Move to the left child
        }
        return hgt; // Return the total height of the left subtree
    }

    // Function to calculate the height of the right subtree
    int findHeightRight(TreeNode* node) {
        int hgt = 0; // Initialize the height counter
        while (node) {
            hgt++;        // Increase height for each level down the right subtree
            node = node->right; // Move to the right child
        }
        return hgt; // Return the total height of the right subtree
    }
};
