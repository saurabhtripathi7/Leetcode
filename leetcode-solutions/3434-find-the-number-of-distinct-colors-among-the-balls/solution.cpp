class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n  = queries.size();
        unordered_map<int,int>colormp;//{color,count}
        unordered_map<int,int>ballmp;//{ball,color}
        vector<int>result;
        for(int i = 0;i<n;i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ballmp.count(ball))
            {
                int precolor = ballmp[ball];
                colormp[precolor]--;
                if( colormp[precolor]==0)
                {
                    colormp.erase(precolor);
                }
            }
            ballmp[ball] = color;
            colormp[color]++;
            result.push_back(colormp.size());
        }
        return result;
    }
};
