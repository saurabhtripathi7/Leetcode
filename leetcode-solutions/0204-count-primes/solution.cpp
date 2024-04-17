class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        int count=0;

        for(int i=2; i < n; i++){
            if(isPrime[i] == true){
                count++;
                for(int j = i*2; j<n; j=j+i){
                    isPrime[j]=false;
                }
            }
        }
        return count;
    }
};
