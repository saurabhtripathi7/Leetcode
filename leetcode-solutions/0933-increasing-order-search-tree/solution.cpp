class Solution {
public:
    // Helper function to perform in-order traversal
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (!root) return;

        inorderTraversal(root->left, inorder);      // Visit left subtree
        inorder.push_back(root->val);              // Process current node
        inorderTraversal(root->right, inorder);    // Visit right subtree
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder); // Get the in-order traversal values

        // Construct the new tree
        TreeNode* newRoot = new TreeNode(inorder[0]); // Start with the first value
        TreeNode* curr = newRoot;                    // Pointer to build the tree

        for (int i = 1; i < inorder.size(); ++i) {   // Start from the second value
            curr->right = new TreeNode(inorder[i]);  // Add a new node to the right
            curr = curr->right;                     // Move the pointer
        }

        return newRoot; // Return the root of the new tree
    }
};

