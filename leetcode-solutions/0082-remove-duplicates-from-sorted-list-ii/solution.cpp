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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == nullptr) return nullptr; //edge case of null head
        
        map<int,int> count;
        //count.first is the value
        //count.second is the frequency

        ListNode* ptr = head;
        while(ptr != nullptr) //counting all the frequencies
        {
            count[ptr->val]++;
            ptr = ptr->next;
        }

        ListNode* newHead = new ListNode(); //new list creation
        ptr = newHead;
        bool node1 = true; //edge case for initial node

        for(auto x:count)
        {
            if(x.second >= 2)continue; //skip if frequency is higher than 2
            else
            {
                if(node1)
                {
                    newHead->val = x.first;
                    newHead->next = NULL;
                    node1 = false;
                }
                else
                {
                    ptr->next = new ListNode(x.first); //nodes addition
                    ptr = ptr->next; 
                }                
            }
        }
        if(node1 == true) //if new list is not created, delete newHead
        {
            delete newHead;
            return nullptr;
        }
        return newHead;
    }
};
