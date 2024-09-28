class Solution {
public:
    int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;  
        num /= 10;        
    }
    return sum;
}
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto it:nums){
            int temp = sumOfDigits(it);
            mini = min(mini, temp);
        }
        return mini;
    }
};
