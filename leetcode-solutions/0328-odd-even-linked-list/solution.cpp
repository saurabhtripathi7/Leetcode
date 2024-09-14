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
    ListNode* oddEvenList(ListNode* head) {
        // If the list is empty or contains only one element, return the head as is.
        if(head == NULL || head->next == NULL) return head;

        // Initialize pointers to track the odd and even nodes.
        // 'odd' points to the first node (which is considered odd).
        ListNode* odd = head;
        // 'even' points to the second node (which is considered even).
        ListNode* even = head->next;
        // Store the head of the even node list so we can attach it later.
        ListNode* evenHead = head->next;

        // Traverse the list, rearranging the next pointers.
        // Continue until we reach the end of the list for either odd or even nodes.
        while(even != nullptr && even->next != NULL) {
            // Move the next pointer of the odd node to the next odd node.
            odd->next = odd->next->next;

            // Move the next pointer of the even node to the next even node.
            even->next = even->next->next;

            // Move the 'odd' pointer to the next odd node.
            odd = odd->next;

            // Move the 'even' pointer to the next even node.
            even = even->next;
        }

        // After processing all odd and even nodes, attach the even list to the end of the odd list.
        odd->next = evenHead;

        // Return the head of the modified list.
        return head;       
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
