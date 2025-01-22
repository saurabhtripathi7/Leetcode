class Solution {
public:
    bool isPossible(int maxWt, vector<int>&weights, int maxDays){
        int sumWt = 0;
        int cnt = 1;
        for(int i = 0; i < weights.size(); ++i){
            if(weights[i] > maxWt) return false;
            if(sumWt + weights[i] <= maxWt){
                sumWt += weights[i];
            }
            else{
                cnt++;
                sumWt = weights[i];
                if(cnt > maxDays) return false; // do: s = mid + 1; 
                // Increase capacity to reduce days
            }
        } 
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = 0;
        int e = accumulate(weights.begin(), weights.end(),0);
        int ans = 0;
        while(s <= e){
            int mid = s+ (e-s)/2;
            if(isPossible(mid, weights, days)){
                ans = mid;
                e =mid - 1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
