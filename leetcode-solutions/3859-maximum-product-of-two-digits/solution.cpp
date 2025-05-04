class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        int maxProd = 0;
        int sz = digits.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i+1; j < sz; ++j) { 
                maxProd = max(maxProd, digits[i] * digits[j]);
            }
        }
        return maxProd;
    }
};
