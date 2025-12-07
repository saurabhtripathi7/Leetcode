class Solution {
public:
    int countOdds(int low, int high) {
        // if both are even → half are odds
        // else → half + 1 are odds
        return (high - low) / 2 + ( (low % 2 == 1 || high % 2 == 1) ? 1 : 0 );
    }
};

