class Solution {
public:
    vector<int> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (long long j = 1LL * i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }
        vector<int> primes;
        for (int i = 2; i <= n; i++)
            if (isPrime[i])
                primes.push_back(i);
        return primes;
    }
    int largestPrime(int n) {
        vector<int> primes = sieve(n);
        vector<bool> isPrime(n + 1, true);

        
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (long long j = 1LL * i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        long long sum = 0, ans = 0;
        for (int p : primes) {
            sum += p;
            if (sum > n)
                break;
            if (isPrime[sum])
                ans = sum;
        }
        return ans;
    }
};
