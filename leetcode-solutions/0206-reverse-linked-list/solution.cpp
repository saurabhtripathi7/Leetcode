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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        
        while(curr != NULL){
            // save the next node
            next = curr->next;
            // reverse the link
            curr->next = prev;

            // move both pointers
            prev = curr;
            curr = next;
        }
        return prev;
        
    }
};
