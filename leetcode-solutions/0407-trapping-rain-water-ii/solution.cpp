class Solution {
public:
    typedef pair<int,pair<int,int>>P;// {height,{i,j}}
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();

        priority_queue<P,vector<P>,greater<P>>cells;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));

        // visit boundary cells first;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(i==0 || i==rows-1 || j==0 || j==cols-1){
                    cells.push({heightMap[i][j],{i,j}});
                    visited[i][j] = true;
                }
            }
        }
        int waterFill = 0;
        // now fill water to certain level with minimal height first
        while(!cells.empty()){
            int height = cells.top().first;
            int i = cells.top().second.first;
            int j = cells.top().second.second;
            cells.pop();
            for(auto dir:directions){
                int new_i = i + dir[0];
                int new_j = j+ dir[1];

                // check out of boundary and not visited yet
                if(new_i < rows && new_i >= 0 && new_j < cols && new_j >= 0 && !visited[new_i][new_j]){
                    waterFill += max(height - heightMap[new_i][new_j],0);
                    cells.push({max(height,heightMap[new_i][new_j]),{new_i,new_j}});
                    visited[new_i][new_j] = true;
                }
            }
        }
        return waterFill;
    }
};
