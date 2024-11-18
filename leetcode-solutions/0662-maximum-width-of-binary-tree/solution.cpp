class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0; // Handle edge case where the tree is empty
        
        int ans = 0;
        queue<pair<TreeNode*, long long>> Q; // Use long long for indices
        Q.push({root, 0});
        
        while (!Q.empty()) {
            int size = Q.size();
            long long minIdx = Q.front().second; // Minimum index at the current level
            long long first, last;
            
            for (int i = 0; i < size; ++i) {
                long long currIdx = Q.front().second - minIdx; // Normalize index to avoid overflow
                TreeNode* node = Q.front().first;
                Q.pop();
                
                if (i == 0) first = currIdx; // First node's index in the level
                if (i == size - 1) last = currIdx; // Last node's index in the level
                
                // Push child nodes into the queue with their respective indices
                if (node->left) Q.push({node->left, currIdx * 2 + 1});
                if (node->right) Q.push({node->right, currIdx * 2 + 2});
            }
            
            ans = max(ans, static_cast<int>(last - first + 1)); // Calculate width and update max width
        }
        
        return ans;
    }
};

