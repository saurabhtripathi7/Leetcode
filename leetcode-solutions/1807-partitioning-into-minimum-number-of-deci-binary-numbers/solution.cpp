class Solution {
public:
    int minPartitions(string n) {
        int ans = 0; // Initialize the answer to 0
        for(auto& ch : n) { // Iterate through each character in the string n
            int num = ch - '0'; // Convert the character to its corresponding integer value
            ans = fmax(ans, num); // Update ans to the maximum value found
        }
        return ans; // Return the maximum digit found
    }
};

