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
    // time/space: O(n)/O(h)
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        helper(root, result);
        return result;
    }
private:
    pair<int, int> helper(TreeNode* node, int& result) {
        // terminate
        if (node == NULL) return {0, 0};

        // recursive
        auto [sum_left, count_left] = helper(node->left, result);
        auto [sum_right, count_right] = helper(node->right, result);

        // calculate the sum and count of the current node
        int sum = node->val + sum_left + sum_right;
        int count = 1 + count_left + count_right;

        // update the result if matched
        if (node->val == (sum / count)){
            result++;
        }

        return {sum, count};
    }
};
