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
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = nextNode->val; //copy next nodes value into current 'node'
        // make the current node point to the next to next node
        node->next = node->next->next;

        // free 
        //delete nextNode;

        
    }
};
