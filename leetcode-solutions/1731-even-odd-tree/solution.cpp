#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
    bool ans = true;  // Assume tree is even-odd until proven otherwise

    // Check for an even level where values should be odd and strictly increasing
    bool checkEvenLevel(const vector<int>& level) {
        if (level.empty()) return true;
        if (level[0] % 2 == 0) return false; // First element must be odd
        for (int i = 1; i < level.size(); ++i) {
            if (level[i] % 2 == 0 || level[i] <= level[i - 1]) { // Not odd or not strictly increasing
                return false;
            }
        }
        return true; // All elements are odd and strictly increasing
    }

    // Check for an odd level where values should be even and strictly decreasing
    bool checkOddLevel(const vector<int>& level) {
        if (level.empty()) return true;
        if (level[0] % 2 != 0) return false; // First element must be even
        for (int i = 1; i < level.size(); ++i) {
            if (level[i] % 2 != 0 || level[i] >= level[i - 1]) { // Not even or not strictly decreasing
                return false;
            }
        }
        return true; // All elements are even and strictly decreasing
    }

    // Function to check the conditions based on the level index `c`
    bool checkLevel(const vector<int>& level, int c) {
        if (c % 2 == 0) {
            return checkEvenLevel(level);
        } else {
            return checkOddLevel(level);
        }
    }

    // BFS function to traverse the tree level by level
    void bfs(TreeNode* root) {
        if (!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        
        while (!q.empty() && ans) {
            int size = q.size();
            vector<int> level;
            
            // Traverse the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                
                level.push_back(curr->val);
            }
            
            // Check the level condition based on the current level index (cnt)
            if (!checkLevel(level, cnt)) {
                ans = false;  // If any condition is not met, set ans to false
            }
            cnt++;
        }
    }

    // Main function to check if the tree is an even-odd tree
    bool isEvenOddTree(TreeNode* root) {
        bfs(root);  // Perform BFS to check all levels
        return ans;  // Return the result
    }
};

