class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int fa = 0, fb = 0;
        for(auto &ch: s){
            if(ch == 'a') fa++;
            else fb++;
        }

        return abs(fa-fb);
    }
};
