class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == nullptr) return 0;

        vector<long long> vec;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            long long sum = 0;  // Use long long for large sums
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
                sum += node->val;
            }
            vec.push_back(sum);
        }

        if (k > vec.size()) return -1;

        sort(vec.begin(), vec.end());
        return vec[vec.size() - k];
    }
};
