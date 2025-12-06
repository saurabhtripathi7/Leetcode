class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        
        long long total = 0;
        vector<long long> diff(n);
        
        for (int i = 0; i < n; i++) {
            total += technique2[i];
            diff[i] = (long long)technique1[i] - (long long)technique2[i];
        }
        
        sort(diff.begin(), diff.end(), greater<long long>());
        
        for (int i = 0; i < k; i++) {
            total += diff[i];  
        }
        
        for (int i = k; i < n; i++) {
            if (diff[i] > 0) total += diff[i];
            else break; 
        }
        
        return total;
    }
};

