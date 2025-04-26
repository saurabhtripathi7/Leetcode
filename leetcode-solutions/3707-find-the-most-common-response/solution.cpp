class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> mp;
        
        for (auto& vec : responses) {
            set<string> st(vec.begin(), vec.end());
            for (auto& str : st) {
                mp[str]++;
            }
        }
        
        int maxFreq = 0;
        string answer = "";
        
        for (auto& [str, freq] : mp) {
            if (freq > maxFreq) {
                maxFreq = freq;
                answer = str;
            } else if (freq == maxFreq) {
                if (str < answer) { 
                    answer = str;
                }
            }
        }
        
        return answer;
    }
};

