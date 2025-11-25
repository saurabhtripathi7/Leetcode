class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int mod = 0;

        for(int i = 1; i <= k; ++i){
            mod *= 10;
            mod += 1;
            mod %= k;
            if(mod == 0) return i;
        }
        return -1;
    }
};
