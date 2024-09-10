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
    int pairSum(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        vector<int>list;
        ListNode* temp = head;
        while(temp){
            list.push_back(temp->val);
            temp = temp->next;
        }
        int currMax = 0;
        int i = 0;
        int j = list.size()-1;

        while(i < j){
            if(list[i] + list[j] > currMax){
                currMax = list[i] + list[j];
            }
            i++;
            j--;
        }
        return currMax;
    }
};
