class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod = 1e9+7;
        int n = corridor.size();
        int cnt = 0;
        long long ans = 1;
        for(auto &c : corridor){
            if(c == 'S') cnt++;
        }
        if(cnt & 1) return 0;
        int i = 0;
        n--;
        while(n >= 0 && corridor[n] == 'P') n--;
        while(i <= n && corridor[i] == 'P') i++;
        if(n <= 0 || i >= n) return 0;

        while(i < n){
            if(corridor[i] == 'S'){
                i++;
                while(i < n ){
                    if(corridor[i] == 'S'){
                        i++;
                        break;
                    }
                    else i++;                    
                }
            }
            else{
                int places = 0;
                while(i < n && corridor[i] == 'P'){
                    i++;
                    places++;
                }
                ans = (1LL*ans*(places+1))%mod;
            }
        }
        return ans;
    }
};
