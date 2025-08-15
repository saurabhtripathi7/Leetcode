class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        double x = log10(n) / log10(4);

        //check if x contains an integral val or not
        return x == (int)x;
    }
};
