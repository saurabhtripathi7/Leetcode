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
    ListNode* reverseBetween(ListNode* head, int start, int end) {
        if (!head || start == end) return head;

        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* prevStart = dummy;

        
        for (int i = 1; i < start; i++) {
            prevStart = prevStart->next;
        }

        ListNode* startNode = prevStart->next;
        ListNode* endNode = startNode;
        ListNode* nextNode = NULL;

        for (int i = start; i < end; i++) {
            nextNode = endNode->next;  
            endNode->next = nextNode->next;  
            nextNode->next = prevStart->next;  
            prevStart->next = nextNode; 
        }

        return dummy->next; 
    }
};
