class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;

        for (int x : nums) {
            bool alive = true;

            while (alive && !st.empty() && st.top() > 0 && x < 0) {
                if (st.top() < -x) {
                    st.pop();
                }
                else if (st.top() == -x) {
                    st.pop();
                    alive = false;
                }
                else {
                    alive = false;
                }
            }

            if (alive) st.push(x);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};