class Solution {
public:
    TreeNode* solve(int preStart, int postStart, int preEnd, vector<int>& preorder, vector<int>& postorder) {
        if (preStart > preEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        if (preStart == preEnd) {
            return root;  // No child case
        }
        
        int nextNode = preorder[preStart + 1];
        int j = postStart;
        
        while (j <= preEnd && postorder[j] != nextNode) {
            j++;
        }
        
        int nodesInLeftSubtree = j - postStart + 1;

        root->left = solve(preStart + 1, postStart, preStart + nodesInLeftSubtree, preorder, postorder);
        root->right = solve(preStart + nodesInLeftSubtree + 1, j + 1, preEnd, preorder, postorder);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(0, 0, n - 1, preorder, postorder);
    }
};

