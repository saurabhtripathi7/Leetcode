class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>> 
        >pq;
        vector<vector<int>>diff(rows, vector<int>(cols, INT_MAX));
        diff[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto [currDiff, rc] = pq.top(); pq.pop();
            auto [currRow, currCol] = rc;

            if(currRow == rows-1 && currCol == cols-1) return currDiff;
            
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};

            for(int i = 0; i < 4; ++i){
                int nr = currRow + dr[i];
                int nc = currCol + dc[i];
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                    int newEffort = max(abs(heights[currRow][currCol] - heights[nr][nc]), currDiff);
                    //cout<<newEffort<<endl;
                    if(newEffort < diff[nr][nc]){
                        diff[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};

