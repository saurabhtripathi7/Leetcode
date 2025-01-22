class Solution {
public:
    bool checker(int minDiff, vector<int>&price, int k){
        int last = price[0];
        int cntPlaced = 1; //place first cow/candy at arr[0] and inc the cnt to 1
        for(int i = 1; i < price.size(); ++i){
            if(price[i] - last >= minDiff){
                last = price[i];
                cntPlaced++;
            }
            if(cntPlaced >= k) return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int s = 0;
        int e = price[n-1]-price[0];
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(checker(mid, price, k)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid -1;
            }
        }
        return ans;
    }
};
