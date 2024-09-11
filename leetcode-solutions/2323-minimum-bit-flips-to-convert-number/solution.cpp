class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        int xorr = start ^ goal; //gives 1 for different bits and 0 for same bit
        
        while(xorr){
            // if the last bit is 1, increment
            ans += (xorr & 1); // & return 1 only when both are 1

            // right shift by 1 digit to check the next bit
            xorr = xorr >> 1;     
        }
        return ans;
    }
};
