class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0, ans = 0;

        for (int i = 0; i < k; ++i) {
            if (st.count(s[i])) cnt++;
        }
        ans = cnt;

        for (int i = k; i < s.size(); ++i) {
            if (st.count(s[i])) cnt++;          
            if (st.count(s[i - k])) cnt--;      
            ans = max(ans, cnt);
        }

        return ans;
    }
};

