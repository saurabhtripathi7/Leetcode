

class Solution {
public:
    // Inorder traversal to collect nodes in sorted order
    void inorder(TreeNode* root, vector<int>& sortedNodes) {
        if (!root) return;
        inorder(root->left, sortedNodes);
        sortedNodes.push_back(root->val);
        inorder(root->right, sortedNodes);
    }

    // Custom binary search to find predecessor and successor
    void binarySearch(const vector<int>& sortedNodes, int query, int& predecessor, int& successor) {
        int left = 0, right = sortedNodes.size() - 1;
        predecessor = -1;
        successor = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (sortedNodes[mid] == query) {
                predecessor = successor = sortedNodes[mid];
                return;
            } 
            else if (sortedNodes[mid] < query) {
                // Move right to find successor
                predecessor = sortedNodes[mid];
                left = mid + 1;
            } 
            else {
                // Move left to find predecessor
                successor = sortedNodes[mid];
                right = mid - 1;
            }
        }
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sortedNodes;
        inorder(root, sortedNodes); // Collect the nodes in sorted order

        vector<vector<int>> ans;

        // For each query, find the predecessor and successor
        for (int query : queries) {
            int predecessor = -1;
            int successor = -1;

            binarySearch(sortedNodes, query, predecessor, successor);

            ans.push_back({predecessor, successor});
        }

        return ans;
    }
};

