class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>countFre(101);

        int maxFre = 0;
        int total = 0;
        for(int num:nums){
            countFre[num]++;
            int fre = countFre[num];
            if(fre>maxFre){
                maxFre = fre;
                total = maxFre;
            }
            else if(fre==maxFre){
                total +=maxFre;
            }
        }
        return total;
    }
};
