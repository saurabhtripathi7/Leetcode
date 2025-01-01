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
    // Helper function to compute both diameter and height in a single traversal
    pair<int, int> diaFast(TreeNode* root) {
        // Base case: if the node is null, return diameter and height as 0
        if (!root) {
            return {0, 0};  // {diameter, height}
        }

        // Recursive calls to calculate diameter and height of left and right subtrees
        pair<int, int> left = diaFast(root->left);   // left subtree result
        pair<int, int> right = diaFast(root->right); // right subtree result

        // Possible diameters:
        // 1. op1: Diameter in the left subtree
        // 2. op2: Diameter in the right subtree
        // 3. op3: Diameter through the root (sum of heights of left and right subtrees)
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        // The diameter at the current node is the maximum of the three options
        pair<int, int> ans;
        ans.first = max({op1, op2, op3}); // Store the largest diameter

        // Height of the current node is the max height of its subtrees plus one
        ans.second = max(left.second, right.second) + 1;

        return ans; // Return both diameter and height for the current node
    }

    // Main function to find the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Only the diameter is needed, so we return the first value of the result
        return diaFast(root).first;
    }
};

