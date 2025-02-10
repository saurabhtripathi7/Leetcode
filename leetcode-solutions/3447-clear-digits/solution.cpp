class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int n = s.size();
        if(n==0)
        return ans;
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            //if current char is a digit than pop the character from the top
            if(!st.empty() && isdigit(s[i]))
            {
                st.pop();
            }
            //else push the character
            else
            {
                st.push(s[i]);
            }
        }
        //extract the ans string from stack
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        //than reverse it
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
