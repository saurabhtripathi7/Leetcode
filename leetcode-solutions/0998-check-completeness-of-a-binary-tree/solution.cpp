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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true; // An empty tree is complete
        
        queue<TreeNode*> q;
        q.push(root);
        bool seenNull = false; // Flag to track if a NULL node has been encountered
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                // Mark that a NULL node has been encountered
                seenNull = true;
            } else {
                // If a NULL node was already encountered and the curr node is NOT Null, the tree is not complete
                if (seenNull) return false;

                // Add child nodes to the queue for processing
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return true; // Tree is complete
    }
};

