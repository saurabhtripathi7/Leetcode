class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> pop(2051, 0);

        // Sweep line difference marking
        for (auto& log : logs) {
            int b = log[0];
            int d = log[1];

            pop[b] += 1; // alive from birth
            pop[d] -= 1; // dead from death year (excluded)
        }

        int maxPop = -1;
        int maxYear = 1950;
        int curr = 0;

        // Prefix sum from 1950 to 2050
        for (int year = 1950; year <= 2050; year++) {
            curr += pop[year]; // number of people alive this year
            if (curr > maxPop) {
                maxPop = curr;
                maxYear = year; // earliest year with maximum population
            }
        }

        return maxYear;
    }
};
