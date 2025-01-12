class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ans(n, 0);
        stack<int>st;

        for(int i = 0; i < n; ++i){
            int curr = temp[i];
            while(!st.empty() && curr > temp[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};
