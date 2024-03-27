class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        int ans = -1;

        while(s <= e){
            long long int mid = s + (e-s)/2;   //to avoid int overflow
            if(mid*mid == x)
                return mid;
            else if (mid*mid < x){
                ans = mid; // if mid square is less than x then it might be or close to the sqrt of x
                // moving to RIGHT to find better ans which could be more close to sqrt of x than prev value of x
                s = mid+1;
            }
            else{
                e = mid-1;
            } 
            
        }
        return ans;
    }
};
