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
private:
    TreeNode* first;  // Pointer to the first swapped node
    TreeNode* middle; // Pointer to the middle node (for adjacent swaps)
    TreeNode* last;   // Pointer to the last swapped node
    TreeNode* prev;   // Pointer to the previous node during in-order traversal

    void inorder(TreeNode* root) {
        if (!root) return; // Base case: if root is null, return

        // Recursive call to traverse the left subtree
        inorder(root->left);

        // Detect swapped nodes
        if (prev != nullptr && root->val < prev->val) {
            // If this is the first violation, mark 'first' and 'middle'
            if (!first) {
                first = prev;
                middle = root;
            }
            // If this is the second violation, mark 'last'
            else {
                last = root;
            }
        }
        // Update 'prev' for the next comparison
        prev = root;

        // Recursive call to traverse the right subtree
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Initialize pointers
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN); // Set 'prev' to the smallest possible value initially

        // Perform in-order traversal to detect swapped nodes
        inorder(root);

        // Recover the tree by swapping the values of the nodes
        if (first && last) {
            // Non-adjacent nodes were swapped
            std::swap(first->val, last->val);
        } else if (first && middle) {
            // Adjacent nodes were swapped
            std::swap(first->val, middle->val);
        }
    }
};

