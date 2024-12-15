class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
         // Initialize the maximum duration with the time of the first button press
        int maxDuration = events[0][1];
        // Initialize the longestButton with the index of the first button
        int longestButton = events[0][0];

        // Traverse the events from the second event onwards
        for (int i = 1; i < events.size(); ++i) {
            // Calculate the time taken to press the current button
            int duration = events[i][1] - events[i - 1][1];

            // Update maxDuration and longestButton if:
            // 1. The current duration is longer than maxDuration.
            // 2. The current duration equals maxDuration but the button index is smaller.
            if (duration > maxDuration || (duration == maxDuration && events[i][0] < longestButton)) {
                maxDuration = duration;       // Update the maximum duration
                longestButton = events[i][0]; // Update the button index
            }
        }

        // Return the button index that took the longest time to press
        return longestButton;
    }
};
