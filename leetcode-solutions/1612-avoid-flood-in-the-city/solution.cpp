class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        unordered_map<int,int>mpp;
        set<int>st;
        int n = rains.size();
        vector<int>result(n,1);
        for(int i = 0;i<rains.size();i++)
        {
            if(rains[i]==0)
            {
                st.insert(i);
            }
            else{
                if(mpp.find(rains[i])!=mpp.end())
                {
                    int lastDay = mpp[rains[i]];
                    auto lb = st.upper_bound(lastDay);
                    if(lb==st.end())
                    {
                        return {};
                    }
                    else
                    {
                        int idx = *lb;
                        mpp.erase(rains[i]);
                        mpp[rains[i]] = i;
                        st.erase(idx);
                        result[idx] = rains[i];
                        result[i] = -1;
                    } 
                }  
                else
                {
                    mpp[rains[i]] = i;
                    result[i] = -1;
                }
            }
        }
        return result;
    }
};
