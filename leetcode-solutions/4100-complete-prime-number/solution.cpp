class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; 1LL * i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }

    bool completePrime(int num) {
        if (!isPrime(num)) return false;

        int digits = 0;
        int tmp = num;
        while (tmp > 0) {
            digits++;
            tmp /= 10;
        }

        long long pow10[11];
        pow10[0] = 1;
        for (int i = 1; i <= digits; i++) {
            pow10[i] = pow10[i - 1] * 10LL;
        }

        for (int k = 1; k <= digits; k++) {
            int prefix = num / (int)pow10[digits - k];
            if (!isPrime(prefix)) return false;
        }

        for (int k = 1; k <= digits; k++) {
            int suffix = num % (int)pow10[k];
            if (!isPrime(suffix)) return false;
        }

        return true;
    }
};

