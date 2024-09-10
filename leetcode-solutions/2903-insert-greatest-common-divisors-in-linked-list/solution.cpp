/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val; // value of the node
 *     ListNode *next; // pointer to the next node in the list
 *     // Default constructor initializing val to 0 and next to nullptr
 *     ListNode() : val(0), next(nullptr) {}
 *     // Constructor that initializes the node with a specific value and sets next to nullptr
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     // Constructor that initializes the node with a specific value and a pointer to the next node
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    // Helper function to compute the greatest common divisor (GCD) of two integers
    int gcd(int a, int b){
        int temp;
        // Using the Euclidean algorithm to compute GCD
        while (b != 0) {
            int temp = b;    // Store the value of b temporarily
            b = a % b;       // Update b with the remainder of a divided by b
            a = temp;        // Set a to the old value of b
        }
        return a; // Return the GCD when b becomes 0
    }

public:
    // Function to insert GCD nodes between every two consecutive nodes in the linked list
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list is empty or has only one node, return the list as is
        if (head == nullptr || head->next == nullptr) return head;
        
        // Pointers to iterate through the list
        ListNode* node1 = head;        // Start with the first node
        ListNode* node2 = head->next;  // The next node

        // Loop through the list until node2 reaches the end
        while (node2) {
            // Calculate the GCD of the values of node1 and node2
            int val = gcd(node1->val, node2->val);
            
            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(val);

            // Insert the new GCD node between node1 and node2
            node1->next = gcdNode;
            gcdNode->next = node2;

            // Move to the next pair of nodes
            node1 = node2;        // node1 becomes node2
            node2 = node2->next;  // Move node2 to the next node in the list
        }
        
        // Return the modified list with the inserted GCD nodes
        return head;
    }
};

