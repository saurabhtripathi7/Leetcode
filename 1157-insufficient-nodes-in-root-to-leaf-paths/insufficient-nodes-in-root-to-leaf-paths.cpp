class Solution {
public:
    int solve(TreeNode* node, int limit, int currSum) {
        if (node == NULL) {
            return INT_MIN;
        }
        currSum += node->val;

        // Leaf
        if (node->left == NULL && node->right == NULL) {
            return currSum < limit ? INT_MIN : node->val;
        }

        int left = solve(node->left, limit, currSum);
        int right = solve(node->right, limit, currSum);

        // Remove insufficient subtrees
        if (left == INT_MIN) {
            node->left = NULL;
        }
        if (right == INT_MIN) {
            node->right = NULL;
        }
        // Both subtrees insufficient
        if (left == INT_MIN && right == INT_MIN) {
            return INT_MIN;
        }
        // At least one sufficient path exists
        return node->val;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (solve(root, limit, 0) == INT_MIN) {
            return NULL;
        }
        return root;
    }
};