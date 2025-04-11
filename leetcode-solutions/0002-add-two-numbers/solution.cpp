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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        // ListNode* temp1 = l1;
        // ListNode* temp2 = l2; 
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        int carry = 0;
    //    we need to continue processing until both l1 and l2 are exhausted and there is no carry left
    //  if are carry is left then again loop will run to create a node
        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = 0;
            if(l1 != NULL){
                val1 = l1->val;
                l1 = l1->next;
            } 
            int val2 = 0;
            if(l2 != NULL){
                val2 = l2->val;
                l2 = l2->next;
            } 
            int sum = carry + val1 + val2;
            int digit = sum%10;
            carry = sum/10;

            // create a newNode at tail to store the digigt
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = newNode;

        }
        return dummy->next;
    }
};
