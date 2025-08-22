class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;   
        for (int x : arr) {
            freq[x]++;
        }

        vector<int> counts(2001, 0); //freq -> occur
        for (auto pair : freq) {
            counts[pair.second]++;   //cnt of freq
            if (counts[pair.second] > 1) return false;
        }        
        return true;
    }
};
//[-1000, -999, .... , 0, 1 ,2, ...., 1000] = 2001


