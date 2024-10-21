class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* res = new ListNode();
        ListNode* pointer = res;
        int carr = 0;
        while(head) {
            int currentVal = (head->val*2 + carr)%10;
            carr = (head->val*2 + carr)/10;
            ListNode* temp = new ListNode(currentVal);
            pointer->next = temp;
            pointer = pointer->next;
            head=head->next;
        }
        if(carr==1) {
            ListNode* temp = new ListNode(1);
            pointer->next = temp;
        }
        res = res->next;
        return reverse(res);
    }

        ListNode* reverse(ListNode* head) {
        ListNode *prev=NULL,*curr=head,*nxt=NULL;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return head=prev;
    }
};
