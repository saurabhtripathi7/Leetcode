class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> minY, maxY, minX, maxX;

        // Initialize with extreme values
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if (!minY.count(x)) minY[x] = INT_MAX;
            if (!minX.count(y)) minX[y] = INT_MAX;
            if (!maxY.count(x)) maxY[x] = INT_MIN;
            if (!maxX.count(y)) maxX[y] = INT_MIN;
            
            minY[x] = min(minY[x], y);
            maxY[x] = max(maxY[x], y);
            minX[y] = min(minX[y], x);
            maxX[y] = max(maxX[y], x);
        }

        int ans = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            
            bool left = (minY[x] < y);
            bool right = (maxY[x] > y);
            bool up = (minX[y] < x);
            bool down = (maxX[y] > x);
            
            if (left && right && up && down) {
                ans++;
            }
        }

        return ans;

    }
};
