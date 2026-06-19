class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1;
        int last = 1, secondLast = 1;

        for(int i = 2; i <= n; ++i){
            int curr = last + secondLast;
            secondLast = last;
            last = curr;
        }
        return last;
    }
};