

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* res = dummyHead;
        ListNode* temp = head->next;

        int cnt = 0;

        while(temp){
           if(temp && temp->val != 0){
            cnt += temp->val;
           } 
            else if(temp && temp->val == 0){
                ListNode* newNode = new ListNode(cnt);
                res->next = newNode;
                res = res->next;
                cnt = 0;
            }
            temp = temp->next;
        }
        return dummyHead->next;        
    }
};



static auto _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

int init= [] {
    std::ofstream out("user.out");
    std::cout.rdbuf(out.rdbuf());    
    for (std::string s; std::getline(std::cin, s);) {
        std::cout << '[';
        int sum = 0;
        for (int _i = 3, _n = s.size() - 2; _i < _n; ++_i) {
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            if (v == 0) {
                std::cout << sum << ',';
                sum = 0;
            } else {
                sum += v;
            }
        }
        std::cout << sum << "]\n";        
    }
    std::exit(0);
    return 0;
}();
