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
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int n=q.size();
            sum=0;

            for(int i=0; i<n; i++){

                TreeNode* ref=q.front();
                q.pop();
                sum +=ref->val;

                if(ref->left){
                    q.push(ref->left);
                }

                if(ref->right){
                    q.push(ref->right);
                }

            }

        }

        return sum;
    }
};
