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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next == NULL) return head;

        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr && curr->next){
            if(curr->val == curr->next->val){
                next = curr->next;
                curr->next = next->next;
                delete next;
            }
            else curr = curr->next;
        }
        return head;
    }
};
