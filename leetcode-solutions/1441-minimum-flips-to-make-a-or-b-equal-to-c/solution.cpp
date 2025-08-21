class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while (a > 0 || b > 0 || c > 0) {
            int abit = a & 1;
            int bbit = b & 1;
            int cbit = c & 1;

            if ((abit | bbit) != cbit) {
                if (cbit == 1) { //flip either bit (since both are 0 and we need atleast 1 1)
                    ans += 1;  
                } else { // if cbit == 0
                    ans += abit + bbit;  //flip that bit which is 1
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};

