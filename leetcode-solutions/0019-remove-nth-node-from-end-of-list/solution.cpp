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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //  optimised soln : one iteration only

        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast pointer n steps ahead
        for(int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        //  fast has reached n placed ahead of slow
        // If fast becomes NULL after the for loop, we are removing the head
        if (fast == NULL)
        {
            ListNode* newHead = head->next;
            delete head; // Free the memory of the old head
            return newHead;
        }
        
        // Move both pointers until fast reaches the last node
        while(fast->next != NULL)
        {
            // move both ptrs simult.
            slow = slow->next;
            fast = fast->next;
            
        }

        // slow->next is the node to be deleted
        ListNode* delNode = slow->next;
        slow->next = slow->next->next; // Skip the node to be deleted
        delete delNode; // Free memory

        return head;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
