/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                Q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                Q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        markParent(root, parent);
        
        // after mapping all node->parent
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*>Q;
        Q.push(target);
        visited[target] = true;
        int curr_dist = 0;

        while(!Q.empty()){
            if(curr_dist == k) break;
            
            int size = Q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* curr = Q.front();
                Q.pop();

                if(curr->left && !visited[curr->left]){
                    Q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    Q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && !visited[parent[curr]]){
                    Q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
            // after process all nodes of this level, inc curr_dist by 1
            curr_dist++;
        }
        vector<int>res;
        while(!Q.empty()){
            TreeNode* front = Q.front();
            Q.pop();
            res.push_back(front->val);
        }
        return res;
    }
};
