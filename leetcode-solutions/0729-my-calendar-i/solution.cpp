#include <vector>
using namespace std;

class MyCalendar {
private:
    vector<vector<int>> arr;

public:
    MyCalendar() {
        // Constructor
    }
    
    bool book(int start, int end) {
        for (const auto& interval : arr) {
            // Check if the new interval overlaps with the existing one
            if (start < interval[1] && end > interval[0]) {
                return false; // Overlapping intervals
            }
        }
        arr.push_back({start, end}); // No overlap, so book the new time
        return true;
    }
};

