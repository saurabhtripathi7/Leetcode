class Solution {
public:
    
    int findMinDifference(std::vector<std::string>& timePoints) {
        int minDiff = INT_MAX;  // Initialize the minimum difference to a very large value (maximum possible)
        std::vector<int> timeArr;  // Vector to store the time points in minutes
        
        // Convert each time point to total minutes and store it in timeArr
        for (int i = 0; i < timePoints.size(); ++i) {
            std::string time = timePoints[i];
            // Extract the hour part (first two characters) and convert to integer
            int hr = std::stoi(time.substr(0, 2));
            // Extract the minute part (last two characters) and convert to integer
            int mint = std::stoi(time.substr(3, 2));

            // Convert hours and minutes to total minutes and add to the timeArr vector
            timeArr.push_back(hr * 60 + mint);
        }

        // Sort the time array in ascending order
        std::sort(timeArr.begin(), timeArr.end());

        // Compare adjacent times in the sorted array to find the minimum difference
        for (int i = 1; i < timeArr.size(); ++i) {
            int currDiff = std::abs(timeArr[i] - timeArr[i - 1]);  // Difference between current and previous time points
            minDiff = std::min(minDiff, currDiff);  // Update minDiff with the smaller value
        }

        // Compare the first and last time points considering the wrap-around case across midnight
        // Wrap-around difference is calculated by subtracting the last time from 1440 (total minutes in a day)
        // and adding the first time to account for the difference across midnight.
        int wrapAroundDiff = 1440 - timeArr.back() + timeArr.front();
        minDiff = std::min(minDiff, wrapAroundDiff);  // Update minDiff with the wrap-around difference if it's smaller

        return minDiff;  // Return the smallest time difference found
    }
};
