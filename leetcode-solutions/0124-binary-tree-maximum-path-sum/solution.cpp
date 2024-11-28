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
    int maxSum; // Global variable to store the maximum path sum across all nodes

    // Helper function to compute the maximum path sum involving a given node
    int solve(TreeNode* root) {
        // Base case: If the node is null, it contributes nothing to the path sum
        if (root == NULL) return 0;

        // Recursively calculate the maximum path sums of the left and right subtrees
        int l = solve(root->left);  // Maximum path sum from the left subtree
        int r = solve(root->right); // Maximum path sum from the right subtree

        // Case 1: "Curved Path" - Maximum sum using both left and right children and the current node
        int curvedAns = l + r + root->val;

        // Case 2: "Straight Path" - Maximum sum using the current node and one of its subtrees
        int eitherLorR = max(l, r) + root->val;

        // Case 3: "Standalone Node" - Only the current node's value contributes to the path sum
        int nodeAns = root->val;

        // Update the global maxSum to store the best path sum seen so far
        // It can come from the curved path, straight path, or just the node itself
        maxSum = max({maxSum, curvedAns, eitherLorR, nodeAns});

        // Return the maximum sum path that can extend to the parent node
        // This can only be the straight path (eitherLorR) or the node itself (nodeAns)
        return max(eitherLorR, nodeAns);
    }

    // Main function to compute the maximum path sum of the tree
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN; // Initialize maxSum to the smallest possible value
        solve(root);      // Start the recursive traversal from the root
        return maxSum;    // Return the final maximum path sum
    }
};

