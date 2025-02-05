class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        vector<int>f1(26,0);
        vector<int>f2(26,0);
        //check whether both the string have same characters set
        for(int i = 0;i<n;i++)
        {
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
        //if characters are different return false
        if(f1!=f2)
        return false;

        int swapcount = 0;
        //count total number of swap positions
        for(int i = 0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            swapcount++;
        }
        
        if(swapcount!=0 && swapcount!=2)
        return false;
        return true;
    }
};
