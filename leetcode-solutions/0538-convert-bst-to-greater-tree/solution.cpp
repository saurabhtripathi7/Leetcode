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
    // Helper function to perform reverse in-order traversal
    void reverseInOrder(TreeNode* root, int& runningSum) {
        // Base case: if the node is null, return
        if (!root) return;

        // Traverse the right subtree first (higher values) in reverse in-order
        reverseInOrder(root->right, runningSum);

        // Update the current node's value by adding it to the running sum
        runningSum += root->val;
        root->val = runningSum;  // Store the cumulative sum in the current node

        // Traverse the left subtree (lower values) in reverse in-order
        reverseInOrder(root->left, runningSum);
    }

    // Main function to convert the BST to GST
    TreeNode* convertBST(TreeNode* root) {
        int runningSum = 0; // Initialize a variable to keep track of the cumulative sum

        // Perform reverse in-order traversal to accumulate the sum and update the tree
        reverseInOrder(root, runningSum);

        // Return the modified root (now transformed into a GST)
        return root;
    }
};

