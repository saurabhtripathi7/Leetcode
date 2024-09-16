/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Initialize two pointers, slow and fast, both starting from the head.
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list with the fast pointer moving two steps and slow moving one step.
        while(fast && fast->next){
            slow = slow->next;        // Move slow by one step
            fast = fast->next->next;  // Move fast by two steps
            
            // If they meet, there is a cycle.
            if(slow == fast){
                // Move slow back to the head.
                slow = head;
                
                // Move both pointers one step at a time until they meet at the cycle start.
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                // When they meet, return the node where the cycle starts.
                return slow;
            }
        }
        
        // If no cycle is detected, return NULL.
        return NULL;
    }
};

