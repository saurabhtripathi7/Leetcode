class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (const auto& account : accounts) {
            int currentWealth = 0;
            for (int j = 0; j < account.size(); j++) {
                currentWealth += account[j];
            }
            maxWealth = max(maxWealth, currentWealth);
        }
        return maxWealth;
    }
};
