/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end()); // O(1) lookup

        // Skip head nodes that should be removed — unlink only (no delete)
        while (head && st.count(head->val)) {
            head = head->next;
        }
        if (!head) return nullptr;

        // Remove nodes after head (unlink only)
        ListNode* temp = head;
        while (temp->next) {
            if (st.count(temp->next->val)) {
                temp->next = temp->next->next; // unlink
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

