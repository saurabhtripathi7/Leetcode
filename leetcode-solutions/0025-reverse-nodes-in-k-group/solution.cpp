class Solution {
public:
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;   // Previous node, initially null
        ListNode* curr = start;     // Current node starts at 'start'

        // Reverse the segment until we reach 'end'
        while (curr != end) {
            ListNode* next = curr->next; // Store next node
            curr->next = prev;           // Reverse the current node's link
            prev = curr;                 // Move 'prev' forward
            curr = next;                 // Move 'curr' forward
        }
        // 'prev' is the new head of the reversed segment
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;

        // Check if there are at least k nodes to reverse
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        // If fewer than k nodes remain, don't reverse and return head as is
        if (count < k) return head;

        // Reverse the current group of k nodes (from 'head' up to 'temp')
        ListNode* new_head = reverse(head, temp);

        // Recursively call for the next group and connect it to the current group
        head->next = reverseKGroup(temp, k);

        // Return new head of the reversed group
        return new_head;
    }
};

