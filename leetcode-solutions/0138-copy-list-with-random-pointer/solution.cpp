/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
        // Function to insert a copy of each node in between the original nodes
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        // Traverse the entire linked list
        while(temp != NULL) {
            Node* nextElement = temp->next; // Store the next node
            
            // Create a new node (copy) with the same data as the original node
            Node* copy = new Node(temp->val);  
            
            // Set the copy's next to the original node's next node
            copy->next = nextElement;  
            
            // Insert the copy between the original node and its next node
            temp->next = copy;         

            // Move to the next original node in the list (skip the copy)
            temp = nextElement;         
        }
    }

    // Function to connect random pointers of the copied nodes
    void connectRandomPointers(Node* head) {
        Node* temp = head;
        // Traverse the list of original and copied nodes
        while(temp != NULL) {
            // Get the copy of the current node
            Node* copyNode = temp->next;    
            
            // If the original node has a random pointer
            if(temp->random) {   
                // Set the copied node's random pointer to point to the copy
                // of the node that the original node's random points to
                copyNode->random = temp->random->next; 
            } else {
                // If the original node's random pointer is NULL, set the
                // copied node's random pointer to NULL as well
                copyNode->random = NULL;   
            }
            
            // Move to the next original node (skip the copied node)
            temp = temp->next->next;   
        }
    }

    // Function to retrieve the deep copy of the linked list
    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        // Create a dummy node to help build the copied list
        Node* dummyNode = new Node(-1);   
        // Pointer to keep track of the deep copied list
        Node* res = dummyNode;             

        // Traverse the combined list of original and copied nodes
        while(temp != NULL) {
            // Link the next pointer of the copied list to the copied node
            res->next = temp->next;
            res = res->next;

            // Restore the original list by skipping the copied nodes
            temp->next = temp->next->next;
            temp = temp->next;
        }
        
        // Return the deep copy, skipping the dummy node
        return dummyNode->next;   
    }

    // Function to clone the linked list
    Node* copyRandomList(Node *head) {
        // If the original list is empty, return null
        if(!head) return nullptr;   
        
        // Step 1: Insert a copy of each node in between the original nodes
        insertCopyInBetween(head); 
        
        // Step 2: Set the random pointers for the copied nodes
        connectRandomPointers(head);  
        
        // Step 3: Separate the original and copied nodes, and return the copied list
        return getDeepCopyList(head); 
    }
};
