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
    // Helper function to reverse the linked list starting from 'head'
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;  // Pointer to traverse the list
        ListNode* prev = NULL;  // Pointer to track the previous node during reversal
        
        // Iterate through the list until 'temp' becomes NULL
        while(temp) {
            ListNode* front = temp->next;  // Save the next node
            temp->next = prev;             // Reverse the 'next' pointer
            prev = temp;                   // Move 'prev' forward
            temp = front;                  // Move 'temp' forward
        }
        return prev;  // 'prev' now points to the new head after reversal
    }

    // Helper function to get the k-th node starting from 'temp'
    ListNode* getKthNode(ListNode* temp, int k) {
        k = k - 1;  // Adjust 'k' to get the correct k-th node (1-based index)
        
        // Traverse the list until we reach the k-th node or the end
        while(temp && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;  // Return the k-th node (could be NULL if k exceeds list size)
    }

    // Main function to reverse nodes in groups of size 'k'
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;     // Pointer to traverse the list
        ListNode* prevLast = NULL; // Pointer to store the last node of the previous group
        
        // Loop until we reach the end of the list
        while(temp) {
            ListNode* KthNode = getKthNode(temp, k);  // Find the k-th node of the current group
            
            if(KthNode == NULL) {  // If there are less than 'k' nodes left
                if(prevLast) prevLast->next = temp;  // Link the last group with the remaining nodes
                break;  // Break the loop as no full group is left
            }
            
            // Store the node after the k-th node to connect later
            ListNode* nextNode = KthNode->next;
            
            // Disconnect the k-th node from the rest of the list to prepare for reversal
            KthNode->next = NULL;

            // Reverse the current group from 'temp' to 'KthNode'
            reverseLL(temp);

            // Adjust the head pointer if this is the first group
            if(temp == head) {
                head = KthNode;
            } else {  // Otherwise, link the previous group's last node to the current group's head (k-th node)
                prevLast->next = KthNode;
            }

            // Update 'prevLast' to be the start of the current group (which is now the last node after reversal)
            prevLast = temp;
            
            // Move 'temp' to the next group
            temp = nextNode;
        }
        return head;  // Return the new head of the list after all groups are reversed
    }
};

