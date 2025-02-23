class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int> maxHeap;

        for(int i = 0; i < grid.size(); ++i) {
            int limit = limits[i];

            nth_element(grid[i].begin(), grid[i].begin() + limit, grid[i].end(), greater<int>());
            
            for(int j = 0; j < limit; ++j) {
                maxHeap.push(grid[i][j]);
            }
        }

        long long sum = 0;
        while(k-- && !maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        
        return sum;
    }
};
