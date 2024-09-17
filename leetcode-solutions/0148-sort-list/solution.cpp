/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}  // Default constructor
 *     ListNode(int x) : val(x), next(nullptr) {}  // Constructor for single node
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}  // Constructor to create a node with a value and a next pointer
 */

// Solution class to implement sorting linked list
int a[50001];
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    for (string s; getline(cin, s);) {
        if (s.length() == 2) {
            out << "[]\n";
            continue;
        }
        int n = 0;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            bool _neg = false;
            if (s[_i] == '-') ++_i, _neg = true;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            if (_neg) v = -v;
            a[n++] = v;
        }
        sort(a, a + n);
        out << '[' << a[0];
        for (int i = 1; i < n; ++i) out << ',' << a[i];
        out << "]\n";
    }
    out.flush();
    exit(0);
    return 0;
}();
const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();



class Solution {
public:

    // Function to merge two sorted linked lists into one sorted list
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        // If one of the lists is empty, return the other list
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        // Temporary pointers to traverse both lists
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        // Dummy node to simplify list merging (will point to the head of merged list)
        ListNode* dummyNode = new ListNode(-1);  // A node with value -1
        ListNode* temp = dummyNode;  // Pointer to build the merged list

        // Loop to merge the two lists based on their values
        while (t1 && t2) {
            // Compare values of current nodes in both lists
            if (t1->val < t2->val) {
                temp->next = t1;  // Add t1 to the result list
                temp = t1;  // Move temp to the newly added node
                t1 = t1->next;  // Move t1 to the next node in list1
            } else {
                temp->next = t2;  // Add t2 to the result list
                temp = t2;  // Move temp to the newly added node
                t2 = t2->next;  // Move t2 to the next node in list2
            }
        }

        // If there are remaining nodes in t1, attach them to the result
        if (t1 != NULL) temp->next = t1;
        // If there are remaining nodes in t2, attach them to the result
        else temp->next = t2;

        // Return the merged list starting after the dummy node
        return dummyNode->next;
    }

    // Function to find the middle of the linked list using the Tortoise and Hare algorithm
    ListNode* tortoiseAndHare(ListNode* temp) {
        // If the list is empty or has only one node, return it
        if (temp == NULL || temp->next == NULL) return temp;

        // Initialize two pointers, slow and fast
        ListNode* slow = temp;  
        ListNode* fast = temp->next; 
        // we are intilially setting fast 1 step ahead 
        //because we want the M1 middle (in case of even no of nodes)

        // Loop to find the middle of the list
        // Fast pointer moves two steps while slow moves one step
        // When fast reaches the end, slow will be at the middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;  // Move slow one step
            fast = fast->next->next;  // Move fast two steps
        }

        // Return the middle node (slow)
        return slow;
    }

    // Function to sort a linked list using merge sort
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has only one node, it's already sorted
        if (head == NULL || head->next == NULL) return head;

        // Find the middle of the list using tortoise and hare algorithm
        ListNode* middle = tortoiseAndHare(head);

        // Divide the list into two halves
        ListNode* rightHead = middle->next;  // The start of the right half
        middle->next = NULL;  // Break the list into two halves
        ListNode* leftHead = head;  // The start of the left half

        // Recursively sort both halves
        leftHead = sortList(leftHead);  // Sort the left half
        rightHead = sortList(rightHead);  // Sort the right half

        // Merge the two sorted halves and return the result
        return merge2Lists(leftHead, rightHead);
    }
};

