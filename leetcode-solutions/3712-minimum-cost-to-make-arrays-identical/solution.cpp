class Solution {
public:
    long long minCost(vector<int>& a, vector<int>& b, long long k) {
        int n = a.size();

        if (a == b) return 0;

        long long withoutSort = 0;
        for (int i = 0; i < n; i++) {
            withoutSort += abs(a[i] - b[i]);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long sortedCost = 0;
        for (int i = 0; i < n; i++) {
            sortedCost += abs(a[i] - b[i]);
        }

        long long totalCost = sortedCost + k;

        return min(withoutSort, totalCost);
    }
};

