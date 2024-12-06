class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st(banned.begin(), banned.end());
        int sum = 0;
        int cnt = 0;

        for(int num = 1; num <= n; ++num){
            if(st.count(num) != 0) continue;
            if (sum + num <= maxSum){
                cnt++;
                sum += num;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};
