class Solution {
public:
    void dfs(TreeNode* node, int& currSum, int targetSum, vector<int>& currPath, vector<vector<int>>& paths) {
        if (node == nullptr) return;

        // Add current node's value to currSum and currPath
        currSum += node->val;
        currPath.push_back(node->val);

        // Check if it's a leaf node and the sum matches the target
        if (currSum == targetSum && node->left == nullptr && node->right == nullptr) {
            paths.push_back(currPath);
        } else {
            // Recursively explore left and right subtrees
            dfs(node->left, currSum, targetSum, currPath, paths);
            dfs(node->right, currSum, targetSum, currPath, paths);
        }

        // Backtrack: Remove the last node's value from currSum and currPath
        currSum -= node->val; //remove nodes val from curr sum bcz passed by ref
        currPath.pop_back(); 
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> currPath;
        int currSum = 0;  // Pass by reference
        dfs(root, currSum, targetSum, currPath, paths);
        return paths;
    }
};
