class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>needed(256); // +ve => required(dont already have in window), -ve => not needed(but already have in the window)
        for(auto x : t) needed[x]++; 
        int req = 0; // no of chars required 
        int startIdx = -1;
        int minLen = INT_MAX;

        int l = 0, r = 0;
        while(r < s.length()){
            int currCh = s[r];
            if(needed[currCh] > 0) req++; // if freq +ve => it is what we are looking for
            needed[currCh]--; // its found, so reduce its freq 

            while(req == t.size()){
                if(minLen > r-l+1){
                    minLen = r-l+1;
                    startIdx = l;
                }
                needed[s[l]]++; 
                if(needed[s[l]] > 0) req--; // s[l] went out of window, hence it would be required
                l++;
            }
            r++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen); 
    }
};