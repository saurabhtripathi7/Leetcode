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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;  // Handle empty list or no rotation needed

        ListNode* tail = head;
        int len = 1;  // Initialize length of the list to 1 (counting the head node)

        // Step 1: Traverse to find the tail and the length of the list
        while (tail->next) {
            len++;
            tail = tail->next;
        }

        // Now, `tail` is the last node, and `len` is the length of the list

        // Step 2: If k is a multiple of len, no rotation needed
        if (k % len == 0) return head;

        // Step 3: Adjust k to be within the bounds of the list length
        k = k % len;

        // Step 4: Make the list circular by linking the tail to the head
        tail->next = head;

        // Step 5: Find the new tail (node before the new head)
        ListNode* newTail = head;
        for (int i = 1; i < len - k; ++i) {
            newTail = newTail->next;
        }

        // Step 6: The new head will be the node after the new tail
        ListNode* newHead = newTail->next;

        // Step 7: Break the circular link to finalize the rotation
        newTail->next = NULL;

        return newHead;  // Return the new head of the rotated list
    }
};

