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
        // Create a dummy node to act as the starting point of the result list
        ListNode* dummy = new ListNode(-1);
        // `tail` will point to the last node in the result list, initially pointing to dummy
        ListNode* tail = dummy;
        // Initialize carry to 0. This will keep track of the carry-over value during addition
        int carry = 0;

        // Continue processing as long as there are nodes left in either l1 or l2, or there is a carry
        while (l1 != NULL || l2 != NULL || carry != 0) {
            // Initialize val1 and val2 to 0
            int val1 = 0;
            int val2 = 0;

            // If l1 is not NULL, get the value and move to the next node
            if (l1 != NULL) {
                val1 = l1->val;
                l1 = l1->next;
            }

            // If l2 is not NULL, get the value and move to the next node
            if (l2 != NULL) {
                val2 = l2->val;
                l2 = l2->next;
            }

            // Calculate the sum of the two digits and the carry
            int sum = carry + val1 + val2;
            // Determine the digit to store in the current node (units place of sum)
            int digit = sum % 10;
            // Update the carry for the next iteration (tens place of sum)
            carry = sum / 10;

            // Create a new node with the digit value
            ListNode* newNode = new ListNode(digit);
            // Append the new node to the result list
            tail->next = newNode;
            // Move the tail pointer to the new node
            tail = newNode;
        }

        // Return the result list, starting from the first node after the dummy
        return dummy->next;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

