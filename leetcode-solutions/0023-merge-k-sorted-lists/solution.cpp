/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}  // Default constructor initializes val to 0 and next to nullptr
 *     ListNode(int x) : val(x), next(nullptr) {}  // Constructor that initializes val to x and next to nullptr
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}  // Constructor that initializes val to x and next to the given node
 * };
 */


class Solution {
public:
    // Function to merge k sorted linked lists into one sorted linked list
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap (priority queue) to store {node value, node pointer} pairs, sorted by the value (for smallest first)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        // Initialize the min-heap with the first node from each linked list, if it's not NULL
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] != NULL){
                pq.push({lists[i]->val, lists[i]});  // Push the {value, node} pair for each non-null list
            }
        } 
        
        // Dummy node to act as the head of the merged linked list
        ListNode* dummyNode = new ListNode(-1);
        // Pointer to track the last node in the merged linked list
        ListNode* temp = dummyNode;
        
        // Continue merging until the min-heap is empty
        while(!pq.empty()){
            // Get the node with the smallest value from the min-heap
            auto it = pq.top();
            pq.pop();  // Remove the top element (the smallest one)

            // If the node has a next node, push its next node into the min-heap
            if(it.second->next != NULL)
                pq.push({it.second->next->val, it.second->next});  // Push {next node value, next node pointer}
            
            // Append the current smallest node to the result list
            temp->next = it.second;
            temp = temp->next;  // Move to the next node in the result list
        }
        
        // Return the merged list starting from the node next to dummyNode (skipping the dummy node itself)
        return dummyNode->next;
    }
};

