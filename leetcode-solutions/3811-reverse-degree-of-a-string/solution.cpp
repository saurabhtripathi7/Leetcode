class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.size(); ++i) {
            int revInd = 'z' - s[i] + 1; 
            int pos = i + 1; 
            total += revInd * pos;
        }
        return total;
    }
};

