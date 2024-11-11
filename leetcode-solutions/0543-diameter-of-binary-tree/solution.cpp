class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;  // Initialize diameter
        height(root, maxi);
        return maxi;
    }

    int height(TreeNode* root, int &maxi) {
        if (!root) return 0;

        int lh = height(root->left, maxi);
        int rh = height(root->right, maxi);

        // Update the maximum diameter found so far
        maxi = max(maxi, lh + rh);

        return 1 + max(lh, rh); // Return height of current node
    }
};

