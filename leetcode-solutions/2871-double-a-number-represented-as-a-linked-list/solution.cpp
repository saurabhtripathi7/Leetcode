class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        ListNode* curr = head;
        ListNode* tail = nullptr;
        int carry = 0;

        while (curr) {
            int val = curr->val * 2 + carry;
            curr->val = val % 10;
            carry = val / 10;
            tail = curr;
            curr = curr->next;
        }

        if (carry) {
            tail->next = new ListNode(carry);
        }

        return reverseList(head);
    }
};
