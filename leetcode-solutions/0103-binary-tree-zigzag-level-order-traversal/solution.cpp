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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // This will store the zigzag level order traversal of the tree.
        
        // If the tree is empty, return an empty result.
        if (!root) 
            return result;

        bool leftToRight = true; // Direction flag for each level, starting left to right.
        queue<TreeNode*> Q; // Queue to facilitate level-order traversal.
        Q.push(root); // Start with the root node in the queue.

        // Loop until there are no more nodes to process.
        while (!Q.empty()) {
            int size = Q.size(); // Number of nodes at the current level.
            vector<int> row(size); // Temporary vector to store values of nodes at this level.

            // Process all nodes at the current level.
            for(int i = 0; i < size; ++i){
                TreeNode* front = Q.front(); // Get the front node in the queue.
                Q.pop(); // Remove the node from the queue.

                // Determine the position to insert the node's value in the row based on the direction.
                int index = (leftToRight) ? i : (size - i - 1);
                row[index] = front->val;

                // Add the left and right children of the current node to the queue for the next level.
                if(front->left) Q.push(front->left);
                if(front->right) Q.push(front->right);
            }

            // Toggle the direction for the next level (left-to-right or right-to-left).
            leftToRight = !leftToRight;

            // Add the processed row for the current level to the final result.
            result.push_back(row); 
        }

        // Return the final zigzag level order traversal.
        return result;
    }
};

