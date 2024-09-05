class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int mSum=0;
        int m = rolls.size(); 
        for(auto it:rolls){
            mSum += it;
        }
        int nSum = mean*(m+n) - (mSum);

        if(nSum < n || nSum > 6 * n) {
            return {};  // Return empty vector if it's impossible
        }

        int each = nSum/n;
        int rem = nSum%n;

        vector<int> result(n, each);

        for(int i=1; i<=rem; i++)
            result[i]++;;

        return result;
        


    }
};
