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
    void dfs(TreeNode* root, unordered_map<int, int>& mpp ){
        if(!root) return;

        dfs(root->left, mpp);
        mpp[root->val]++;
        dfs(root->right, mpp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int>mpp;
        dfs(root, mpp);

        vector<int>ans;
        int maxFreq = 0;
        for(auto pair:mpp){
            maxFreq = max(maxFreq, pair.second);
        }
        for(auto pair:mpp){
            if(pair.second == maxFreq){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};
