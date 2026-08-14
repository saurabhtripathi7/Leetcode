
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;
        for (ListNode* node : lists) {
            if (node) pq.push({node->val, node});
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!pq.empty()){
            auto [val, node] = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;
            ListNode* temp = node;
            temp = temp->next;
            if(temp) pq.push({temp->val, temp});

        }
        return dummy->next;
    }
};