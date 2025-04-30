class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (auto& num : nums) {

            int digits = (int)log10(num) + 1;
            if (digits % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};
