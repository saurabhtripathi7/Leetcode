#include <string>
#include <tuple>
using namespace std;

class Solution {
public:
    // Fast modular exponentiation modulo 10.
    int modExp(int base, int exp) {
        int res = 1;
        while(exp > 0) {
            if(exp & 1)
                res = (res * base) % 10;
            base = (base * base) % 10;
            exp /= 2;
        }
        return res;
    }
    
    // Modular inverse modulo 10 for numbers coprime with 10.
    int modInv(int a) {
        // Only 1, 3, 7, and 9 are invertible modulo 10.
        if(a == 1) return 1;
        if(a == 3) return 7;
        if(a == 7) return 3;
        if(a == 9) return 9;
        return 0; // Should not occur if a is coprime with 10.
    }
    
    // Factorize x into (val, cnt2, cnt5) where:
    //   x = val * 2^(cnt2) * 5^(cnt5)  and  val is coprime with 10.
    tuple<int, int, int> factorize(int x) {
        int cnt2 = 0, cnt5 = 0;
        while(x % 2 == 0) { cnt2++; x /= 2; }
        while(x % 5 == 0) { cnt5++; x /= 5; }
        return {x % 10, cnt2, cnt5};
    }
    
    bool hasSameDigits(string s) {
        int n = s.size();
        int r = n - 2; // r rounds are applied (n-2 rounds)
        
        // S1 and S2 will accumulate the contributions for the final two digits.
        int S1 = 0, S2 = 0;
        
        // Our current binom coefficient (starting with binom(r, 0) = 1)
        int C_val = 1;   // The part coprime with 10.
        int C2 = 0, C5 = 0; // Count of factors 2 and 5.
        
        // For i = 0: contribution is binom(r, 0) * d[0] and binom(r, 0) * d[1].
        S1 = (S1 + (s[0] - '0')) % 10;
        S2 = (S2 + (s[1] - '0')) % 10;
        
        // Now iterate i from 1 to r.
        for (int i = 1; i <= r; i++) {
            // Compute numerator = r - i + 1 and factorize it.
            int num = r - i + 1;
            auto [num_val, num2, num5] = factorize(num);
            // Factorize denominator = i.
            int den = i;
            auto [den_val, den2, den5] = factorize(den);
            
            // Multiply by the numerator.
            C_val = (C_val * (num_val % 10)) % 10;
            C2 += num2;
            C5 += num5;
            
            // "Divide" by the denominator: subtract the factors from the counts...
            C2 -= den2;
            C5 -= den5;
            // ...and multiply by the modular inverse of the denominator’s reduced part.
            C_val = (C_val * modInv(den_val)) % 10;
            
            // Now the current binom coefficient is:
            //      current = C_val * 2^(C2) * 5^(C5)  (as an integer)
            // But note: if both C2 and C5 are at least 1, then 2*5=10 divides it and current mod 10 is 0.
            int current;
            if(C2 >= 1 && C5 >= 1)
                current = 0;
            else {
                int factor2 = (C2 > 0 ? modExp(2, C2) : 1);
                int factor5 = (C5 > 0 ? modExp(5, C5) : 1);
                current = (C_val * ((factor2 * factor5) % 10)) % 10;
            }
            
            // Update S1 and S2 with the contributions from digit positions i and i+1.
            S1 = (S1 + current * (s[i] - '0')) % 10;
            S2 = (S2 + current * (s[i+1] - '0')) % 10;
        }
        
        // The final two digits (after all rounds) are S1 and S2 modulo 10.
        return S1 % 10 == S2 % 10;
    }
};
