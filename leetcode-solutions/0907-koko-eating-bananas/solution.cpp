class Solution {
public:
    int maxElementInArray(vector<int>& piles){
        int size = piles.size();
        int maxi= INT_MAX;
        for(int i=0; i < size; i++){
            maxi = std::max(maxi, piles[i]);
        }
        return maxi;

    }
    int findTotalHour(vector<int>& piles, int mid){
        int totalH = 0;
        for (int i = 0; i < piles.size(); i++){
            totalH += ceil((double)(piles[i]) / (double)(mid));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s = 1;
        int e = maxElementInArray(piles);
        
        while(s <= e){
            int mid = s + (e-s)/2;

            int totalH = findTotalHour(piles, mid);
            if(totalH <= h){
                e = mid - 1;
            } 
            else{
                s = mid + 1;
            }
        }
        return s;
    }
};
