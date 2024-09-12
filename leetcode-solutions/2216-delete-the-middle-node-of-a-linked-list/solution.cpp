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
    ListNode* deleteMiddle(ListNode* head) {
         // Edge case: if the list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // Initialize slow, fast, and preSlow pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* preSlow = nullptr;

        // Traverse the list with slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            preSlow = slow;         // preSlow tracks the node before slow
            slow = slow->next;      // slow moves one step
            fast = fast->next->next; // fast moves two steps
        }

        // Now, slow is at the middle, and preSlow is the node before slow
        // Delete the middle node
        if (preSlow != nullptr) {
            preSlow->next = slow->next;
        }
        delete slow; // Free the memory of the middle node

        return head;
        
    }
};
