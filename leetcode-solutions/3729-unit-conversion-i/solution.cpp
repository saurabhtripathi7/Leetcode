class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        
        vector<pair<int, int>> adj[n];
        
        for (auto& conversion : conversions) {
            int src = conversion[0], tgt = conversion[1], factor = conversion[2];
            adj[src].push_back({tgt, factor});
            adj[tgt].push_back({src, 1});
        }

        vector<int> baseUnitConversion(n, -1);
        baseUnitConversion[0] = 1;  

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& neighbor : adj[node]) {
                int neighborType = neighbor.first;
                int conversionFactor = neighbor.second;

                if (baseUnitConversion[neighborType] == -1) {
                    baseUnitConversion[neighborType] =
                        (1LL * baseUnitConversion[node] * conversionFactor) % MOD;
                    q.push(neighborType);  
                }
            }
        }

        return baseUnitConversion;
    }
};

