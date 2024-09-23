static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

inline bool is_digit(const char c) {
    return (c >= '0') && (c <= '9');
}

inline bool is_critical_point(const int n1, const int n2, const int n3) {
    return (n1 > n2) && (n2 < n3)
           || (n1 < n2) && (n2 > n3);
}

static bool IllegalFastSolve = [](){
    std::ofstream out("user.out");
    std::string s;
    while (std::getline(std::cin, s)) {
        int n1 = -1;
        int n2 = -1;
        int n3 = -1;
        int first_crit_idx = -1;
        int prev_crit_idx = -1;
        int number = 0;
        int idx = 0;
        int min_dist = std::numeric_limits<int>::max();

        for (int i = 1; i < s.size(); ++i) {
            if (is_digit(s[i])) {
                number = 10 * number + (s[i] - '0');
            } else {
                n1 = n2;
                n2 = n3;
                n3 = number;

                if (n1 != -1) {
                    if (is_critical_point(n1, n2, n3)) {
                        if (first_crit_idx == -1) {
                            first_crit_idx = idx;
                        } else {
                            min_dist = std::min(min_dist, idx - prev_crit_idx);
                        }
                        prev_crit_idx = idx;
                    }
                }
                number = 0;
                ++idx;
            }
        }
        if (min_dist == std::numeric_limits<int>::max()) {
            out << "[-1,-1]\n";
        } else {
            const int max_dist = prev_crit_idx - first_crit_idx;
            out << "[" << min_dist << "," << max_dist << "]\n";
        }
    }
    out.flush();
    exit(0);
    return true;
}();

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        vector<int> pos; 
        int cnt = 0;     

        while (curr->next) {
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

