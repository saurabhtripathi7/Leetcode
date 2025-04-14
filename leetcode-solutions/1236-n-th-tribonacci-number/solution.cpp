class Solution {
public:
    int trib(int n, vector<int>&f){
        if(n == 0) return 0;
        if(n == 1 || n ==2 ) return 1;
        
        if(f[n] != -1) return f[n];

        return f[n] = trib(n-1, f) + trib(n-2, f) + trib(n-3, f);
    }
    int tribonacci(int n) {
        vector<int>f(38, -1);
        return trib(n, f);
    }
};
