class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        std::transform(para.begin(), para.end(), para.begin(), ::tolower);
        unordered_map<string, int>mpp;
        string s = "";
        for (char ch : para) {
            if (isalpha(ch)) {
                s += ch;  
            } else if (!s.empty()) {
                mpp[s]++;  
                s = "";                }
        }
        
        // Handle the last word (if any)
        if (!s.empty()) mpp[s]++;

        for(int i=0;i<banned.size();i++) mpp[banned[i]]=-1;
        
        int maxi = INT_MIN;
        string ans;
        for(auto pair : mpp){
            string word = pair.first;
            // if(st.count(word) != 0) continue;

            int freq = pair.second;
            if(freq > maxi){
                maxi = freq;
                ans = word;
            }
        }
        return ans;
    }
};
