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
    void bfs(TreeNode* root){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            
            vector<TreeNode*>level;
            for(int i = 0; i < size; ++i){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                level.push_back(curr);
            }
            if(cnt % 2 != 0){
                int i = 0; int j = size-1;
                while(i <= j){
                    swap(level[i]->val, level[j]->val);
                    i++;
                    j--;
                }
            }
            cnt++;
             
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
};
