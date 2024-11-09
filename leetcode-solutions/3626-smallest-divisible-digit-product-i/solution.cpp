class Solution {
public:
    int product(int num)
    {
        int prod = 1;
        while(num){
            int digit = num%10;
            prod *= digit;
            num = num/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) 
    { 
        for(int i = n; i < n+t; ++i){
            if(product(i) % t == 0) return i;
        }
        return -1;
    }
};
