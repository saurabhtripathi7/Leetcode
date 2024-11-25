// Definition for a TreeNode.
class Solution {
public:
    // Function to calculate the minimum number of swaps required to sort the array
    int minSwaps(vector<int> arr, int n) {
        // Create a vector of pairs where each pair contains the array element and its index
        vector<pair<int, int>> ve;
        for (int i = 0; i < n; i++) {
            ve.push_back({arr[i], i});
        }

        // Sort the array based on the first value (the actual element)
        sort(ve.begin(), ve.end());

        // Counter for the number of swaps
        int cnt = 0;

        // Traverse the array and count swaps using cycle detection
        for (int i = 0; i < n; i++) {
            // If the element is already in its correct position, skip
            if (ve[i].second == i) continue;

            // Otherwise, swap the current element with the correct position
            cnt++;
            swap(ve[i], ve[ve[i].second]);

            // Since the current index might still not be in the correct position, repeat
            i--;
        }

        // Return the total number of swaps
        return cnt;
    }

    // Function to calculate the minimum number of operations to sort the values at each level of the tree
    int minimumOperations(TreeNode* root) {
        // If the tree is empty, no operations are required
        if (!root) return 0;

        // Queue to perform level-order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Variable to store the total number of swaps
        int ans = 0;

        // Perform level-order traversal
        while (!q.empty()) {
            // Temporary vector to store the values at the current level
            vector<int> tempp;
            int sz = q.size(); // Number of nodes at the current level

            // Traverse all nodes at the current level
            while (sz--) {
                TreeNode* curr = q.front(); // Get the front node from the queue
                q.pop();                    // Remove the node from the queue

                tempp.push_back(curr->val); // Store its value in the temporary vector

                // Add left and right children to the queue, if they exist
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Calculate the number of swaps required to sort the current level
            int kk = tempp.size();
            ans += minSwaps(tempp, kk); // Add the swaps for this level to the total
        }

        // Return the total number of swaps for all levels
        return ans;
    }
};

