class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string>org = {"0", "1"};
        
        for(int i = 2; i <= n; ++i){
            int size = org.size();
            vector<string>rev = org;
            reverse(rev.begin(), rev.end());
            for (int i = 0; i < size; ++i) {
                org[i] = "0" + org[i];
            }

            for (int i = 0; i < size; ++i) {
                org.push_back("1" + rev[i]);
            }
        }

        vector<int>res;
        for(auto str: org){
            res.push_back(stoi(str, nullptr, 2));
        }
        return res;
    }
};
