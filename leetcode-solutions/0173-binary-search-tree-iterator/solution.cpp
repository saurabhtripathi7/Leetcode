/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> myStack; // Stack to store nodes for controlled traversal

public:
    // Constructor initializes the stack with the leftmost path starting from the root
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    // Returns whether there are more nodes to process
    bool hasNext() {
        return !myStack.empty();
    }

    // Returns the next smallest value in the BST
    int next() {
        // Get the top node (smallest unprocessed node)
        TreeNode* currentNode = myStack.top();
        myStack.pop(); // Remove it from the stack

        // If there’s a right subtree, add all its left children to the stack
        if (currentNode->right != nullptr) {
            pushAllLeft(currentNode->right);
        }

        // Return the value of the current node
        return currentNode->val;
    }

private:
    // Helper function to push all left nodes of a subtree to the stack
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            myStack.push(node); // Add the current node to the stack
            node = node->left;  // Move to the left child
        }
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
