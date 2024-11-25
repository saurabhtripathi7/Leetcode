class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse;

public:
    // Constructor initializes the iterator with the root and direction of traversal.
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    // Checks if there are more nodes in the BST iterator.
    bool hasNext() {
        return !myStack.empty();
    }

    // Returns the next smallest or largest number based on traversal direction.
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if (reverse) {
            pushAll(tmpNode->left); // If reverse, process left subtree (decreasing order).
        } else {
            pushAll(tmpNode->right); // Otherwise, process right subtree (increasing order).
        }
        return tmpNode->val;
    }

private:
    // Pushes all nodes along the path (left/right based on direction) onto the stack.
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            myStack.push(node);
            if (reverse) {
                node = node->right; // Reverse traversal moves towards the right.
            } else {
                node = node->left; // Normal traversal moves towards the left.
            }
        }
    }
};

class Solution {
public:
    // Checks if there exist two elements in the BST that sum up to k.
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        // Create two BSTIterators: one for smallest values and one for largest values.
        BSTIterator left(root, false); // In-order traversal (small to large).
        BSTIterator right(root, true); // Reverse in-order traversal (large to small).

        int i = left.next(); // Start with the smallest element.
        int j = right.next(); // Start with the largest element.

        // Use a two-pointer approach to find the target sum.
        while (i < j) {
            if (i + j == k) {
                return true; // Found a pair with the required sum.
            } else if (i + j < k) {
                i = left.next(); // Move the left pointer to a larger value.
            } else {
                j = right.next(); // Move the right pointer to a smaller value.
            }
        }
        return false; // No such pair exists.
    }
};

