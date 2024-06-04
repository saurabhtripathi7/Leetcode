class Solution {
public:
    
    bool isPossible(vector<int>& arr, int mid, int m, int k){
        int bouquet = 0, count=0;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= mid){
                count++;
            }
            else{
                bouquet += count/k;
                count = 0;
            }
        }
        bouquet += count/k;

        if(bouquet >= m) return true;
        else return false;


    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > n/k) return -1;
       // finding min and max in the array 
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

    
        //if(m*k > n) return -1;
     
        int start = mini;
        int end = maxi;
        
        // int start=*min_element(bloomDay.begin(),bloomDay.end());
        // int end=*max_element(bloomDay.begin(),bloomDay.end());

        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossible(bloomDay, mid, m, k)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }       
        }
        return start;
    
    }
};
