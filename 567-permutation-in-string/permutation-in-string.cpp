class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;

        vector<int>mp1(26), mp2(26);

        for(int i = 0; i < n1; ++i){
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++; // 1st window of s2 of size n1
        }
        if(mp1 == mp2) return true;

        for(int i = n1; i < n2; ++i){
            mp2[s2[i] - 'a']++;
            mp2[s2[i-n1] - 'a']--;

            if(mp1 == mp2) return true;
        }
        return false;
    }
};