class Solution {
public:
    bool canAliceWin(int n) {
        int curr = 10;
        while (n > 0) {
            if (n < curr)
                return false;
            n -= curr--;
            if (n < curr)
                return true; 
            n -= curr--; 
        }
        return false;
    }
};
