class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int m=mat.size(), n=mat[0].size(), N=m*n;

        vector<int> to_i(N+1), to_j(N+1);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int x=mat[i][j];
                to_i[x]=i;
                to_j[x]=j;
            }
        }
        vector<int> row(m), col(n);
        for(int i=0; i<N; i++){
            int x=arr[i];
            if (++row[to_i[x]]==n || ++col[to_j[x]]==m) return i;
        }
        return -1;
    }
};
