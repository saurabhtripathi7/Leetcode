class Solution {
private:
    bool canShipWithinDays(const vector<int>& weights, int capacity, int days) {
        int daysNeeded = 1; // Start on Day 1
        int currentLoad = 0;
        
        for (int weight : weights) {
            // If adding the next package exceeds the ship's capacity
            if (currentLoad + weight > capacity) {
                daysNeeded++;        // Send the ship, start a new day
                currentLoad = weight; // This package goes on the new ship
                
                // Early exit optimization
                if (daysNeeded > days) {
                    return false;
                }
            } else {
                // Otherwise, load it onto the current ship
                currentLoad += weight;
            }
        }
        
        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        // low is the max single weight (must be able to carry the heaviest item)
        int low = *max_element(weights.begin(), weights.end());
        
        // high is the sum of all weights (can carry everything in 1 day)
        // Using accumulate requires <numeric>. Using long long to prevent overflow.
        long long high = accumulate(weights.begin(), weights.end(), 0LL);
        
        int optimalCapacity = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canShipWithinDays(weights, mid, days)) {
                optimalCapacity = mid; // This capacity works, record it
                high = mid - 1;        // Try to find a smaller, cheaper ship
            } else {
                low = mid + 1;         // Ship is too small, takes too many days
            }
        }
        return optimalCapacity;
    }
};