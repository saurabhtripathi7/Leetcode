class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        vector<int> pos; 
        int cnt = 0;     

        while (curr && curr->next) {
            ListNode* next = curr->next;
            cnt++;
            
            if (prev) {
                // Checking for local minima
                if (curr->val < prev->val && curr->val < next->val) {
                    pos.push_back(cnt);
                }
                // Checking for local maxima
                else if (curr->val > prev->val && curr->val > next->val) {
                    pos.push_back(cnt);
                }
            }

            
            prev = curr;
            curr = curr->next;
        }

        if (pos.size() < 2) {
            return {-1, -1}; 
        }

        vector<int> ans(2, -1);
        int mini = INT_MAX; 
        int maxi = pos.back() - pos[0]; 
        
        for (int i = 1; i < pos.size(); ++i) {
            mini = min(mini, pos[i] - pos[i-1]);
        }

        ans[0] = mini;
        ans[1] = maxi;

        return ans;
    }
};
