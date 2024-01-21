class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;        
        int n=mat.size();
        int oneCount= INT_MIN;
        int rowNo=-1;

        for(int i=0; i<n; i++){
            // har row se pehle
            int OneInEachRow=0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==1){
                    OneInEachRow++;
                }
            }
            // after each row, updating variables which are outside the for loop
            if(OneInEachRow>oneCount){
                oneCount=OneInEachRow;
                rowNo=i;
            }
        }
        ans.push_back(rowNo);
        ans.push_back(oneCount);
        return ans;
    }
};
