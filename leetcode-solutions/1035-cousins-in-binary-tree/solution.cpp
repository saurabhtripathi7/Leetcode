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
class Solution {
public:
    void markParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        TreeNode* n1 = NULL;
        TreeNode* n2 = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            bool foundX = false;
            bool foundY = false;
            for (int i = 0; i < size; ++i) {
                auto curr = q.front();
                q.pop();
                
                if (curr->val == x){
                    foundX = true;
                    n1 = curr;
                }
                if (curr->val == y){
                    foundY = true;
                    n2 = curr;
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if (foundX && foundY && parent[n1] != parent[n2]) return true;
        }
        return false;
    }
};
