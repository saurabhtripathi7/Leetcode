class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(auto &num: nums){
            int digits = (int)log10(num) + 1;
            if(digits == 1) ones += num;
            else twos += num;
        }
        return ones == twos ? false : true;
    }
};
