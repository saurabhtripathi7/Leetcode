// Post-order DFS with State Tracking
class Solution {
public:
    // Returns {money_if_rob, money_if_skip} for the subtree rooted at 'node'
    pair<int, int>dfs(TreeNode* node){
        if(!node) return {0, 0};

        auto leftChildAns = dfs(node->left);
        auto rightChildAns = dfs(node->right);
        
        // If we rob this node, we cannot rob its children
        int rob = node->val + leftChildAns.second + rightChildAns.second;
        
        // If we skip this node, we take the best of each child independently
        int skip = max(leftChildAns.first, leftChildAns.second) + max(rightChildAns.first, rightChildAns.second);

        return {rob, skip};      
    }
    int rob(TreeNode* root) {
        pair<int, int>res = dfs(root); //{pick, skip};
        return max(res.first, res.second);
    }
};