class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       long long int totalReqSum = 0;
        
        for(int i : chalk){
            totalReqSum += i;
        }

        int remChalk = k % totalReqSum;

        for(int i = 0; i < chalk.size(); i++){
            if(remChalk < chalk[i]){
                return i;
            }
            remChalk -= chalk[i];
        }
        return 0;
    }
};
