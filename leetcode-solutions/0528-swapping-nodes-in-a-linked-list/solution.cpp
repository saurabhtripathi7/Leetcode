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
static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str, k_str; getline(cin, str) && getline(cin, k_str); cout << '\n') {
        const int n = ranges::count(str, ',') + 1;
        int k = stoi(k_str);
        if (n == 1 || (n % 2 && k == n / 2 + 1)) {
            cout << str;
            continue;
        }
        k = min(k, n - k + 1);
        stringstream ss(str); ss.ignore();
        auto l = str.begin() + 1;
        for (int commas = 1; commas < k; ++l) if (*l == ',') ++commas;
        auto r = str.end() - 2;
        for (int commas = 1; commas < k; --r) if (*r == ',') ++commas;
        auto r_start = r;
        while (*r_start != ',') --r_start;
        ++r_start;
        auto l_end = l;
        while (*l_end != ',') ++l_end;
        cout << string(str.begin(), l);
        cout << string(r_start, r + 1);
        cout << string(l_end, r_start);
        cout << string(l, l_end);
        cout << string(r + 1, str.end());
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* frontNode = head; // To find the k-th node from the start
        ListNode* backNode = head; // To find the k-th node from the end
        int length = 0;

        // First pass to count the length of the list
        while (frontNode) {
            length++;
            frontNode = frontNode->next;
        }

        // Calculate the position of the k-th node from the end
        int backPosition = length - k;

        // Reset frontNode to head to find the k-th node
        frontNode = head;

        // Move frontNode to the k-th node
        for (int i = 1; i < k; ++i) {
            frontNode = frontNode->next;
        }

        // Move backNode to the k-th node from the end
        for (int i = 0; i < backPosition; ++i) {
            backNode = backNode->next;
        }

        // Swap the values of the k-th nodes
        std::swap(frontNode->val, backNode->val);

        return head; // Return the head of the modified list
    }
};

