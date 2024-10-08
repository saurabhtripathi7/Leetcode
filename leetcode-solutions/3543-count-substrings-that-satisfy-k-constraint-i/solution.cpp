class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int zeros = 0, ones = 0;
        while(r < s.length()){
            if(s[r] == '0') zeros++;
            else ones++;
            while(zeros > k && ones > k){
                if(s[l] == '0') zeros--;
                else if(s[l] == '1') ones--;
                l++;
            }
            if(zeros <= k || ones <= k) cnt += r-l+1;
            r++;
        }
        return cnt;
        
    }
};
