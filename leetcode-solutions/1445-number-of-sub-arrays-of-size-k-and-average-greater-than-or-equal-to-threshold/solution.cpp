class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int size = 0;
        int sum = 0;
        while(r < arr.size()){
            size++;
            sum += arr[r];
            if(size > k ){
                sum -= arr[l];
                l++;
                size--;
            }
            if(size == k){
                if(sum >= k*threshold) cnt++;
            }
            r++;
        }
        return cnt;
    }
};
