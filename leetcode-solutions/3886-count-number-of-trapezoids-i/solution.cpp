class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;  // y-coord -> count
        const long long MOD = 1000000007LL;

        // Count how many points on each y-level
        for (auto &coord : points) {
            mp[coord[1]]++;
        }

        long long ans = 0;
        long long prevEdges = 0; 

        for (auto &p : mp) {
            long long freq = p.second;  

            long long currEdges = (freq * (freq - 1) / 2) % MOD;

            ans = (ans + (prevEdges * currEdges) % MOD) % MOD;
            prevEdges = (prevEdges + currEdges) % MOD;
        }

        return (int)(ans % MOD);
    }
};

