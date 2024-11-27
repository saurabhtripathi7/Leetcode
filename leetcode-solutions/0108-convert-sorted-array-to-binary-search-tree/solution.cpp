class Solution {
public:
    TreeNode* buildBST(vector<int>& nums, int s, int e){
        if(s > e) return NULL;  // Use '>' instead of '>=', as we want to include 's' and 'e' in the range
        
        int mid = (s + e) / 2;  // Find the middle element

        TreeNode* root = new TreeNode(nums[mid]);  // Create the root with the middle element
        root->left = buildBST(nums, s, mid - 1);  // Left subtree from the range [s, mid - 1]
        root->right = buildBST(nums, mid + 1, e);  // Right subtree from the range [mid + 1, e]
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);  // Start from the entire range
    }
};

