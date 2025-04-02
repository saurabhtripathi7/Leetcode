class Solution {
public:
void dfs (int i,int j, int n,int m, vector<vector<int>>& visited, vector<vector<char>>& board){
    if (i<0||j<0||i>=n||j>=m|| visited[i][j]==1 || board[i][j]=='.'){
        return ;
    }
    visited[i][j]=1;
    dfs(i+1,j,n,m,visited,board);
    dfs(i-1,j,n,m,visited,board);
    dfs(i,j-1,n,m,visited,board);
    dfs(i,j+1,n,m,visited,board);

    
}
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n, vector<int> ( m , 0));
        int count=0;
        for (int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
                if (board[i][j]=='X' && visited[i][j]==0){
                    dfs(i,j,n,m,visited, board);
                    count++;
                }
            }
        }
        return count;
        
    }
};
