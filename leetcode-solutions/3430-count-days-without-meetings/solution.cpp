class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        //edge case:
        if(meetings.empty()) return days;

        sort(meetings.begin(), meetings.end());
        int gap = 0;
        int last = 0;

        for(auto meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];

            if (start > last + 1) {
                gap += (start - last - 1);
            }

            last = max(last, end);
        }
        //edge case: Count free days after the last meeting 
        gap += (days - last);

        return gap;
    }
};
