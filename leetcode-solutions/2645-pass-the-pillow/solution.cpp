class Solution {
public:
    int passThePillow(int n, int time) {
         // Calculate the number of full back-and-forth chunks
    int chunks = time / (n - 1);

    // Calculate the remainder of time within a single back-and-forth cycle
    int remainder = time % (n - 1);

    // Determine the position based on the number of chunks and direction
    if (chunks % 2 == 0) {
        // If the number of chunks is even, the direction is the same as the start
        // The position is straightforward
        return remainder + 1;
    } else {
        // If the number of chunks is odd, the direction is reversed
        // The position needs to be calculated based on the reversed direction
        return n - remainder;
    }
    }
};
