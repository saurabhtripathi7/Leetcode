class Solution {
public:
    ListNode* findMiddle(ListNode* start, ListNode* end) {
        ListNode* slow = start;
        ListNode* fast = start;

        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // Return the middle node
    }

    TreeNode* helper(ListNode* start, ListNode* end) {
        if (start == end) return nullptr; // Base case: empty range

        // Find the middle node in the current range
        ListNode* mid = findMiddle(start, end);

        // Create a tree node with the middle node's value
        TreeNode* root = new TreeNode(mid->val);

        // Recursively build the left and right subtrees
        root->left = helper(start, mid); // Left range is [start, mid)
        root->right = helper(mid->next, end); // Right range is (mid, end)

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr); // Pass `nullptr` as the end marker
    }
};

