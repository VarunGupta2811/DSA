class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>&visited){
       if(i<0 || i>=n || j<0 || j>=m) return;
       if(visited[i][j] || board[i][j]=='X') return;
       visited[i][j]=true;
       dfs(i-1,j,board,visited);
       dfs(i+1,j,board,visited);
       dfs(i,j-1,board,visited);
       dfs(i,j+1,board,visited);
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,visited);//first column
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,visited);//last column
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(0,j,board,visited);//first row
            }
            if(board[n-1][j]=='O'){
                dfs(n-1,j,board,visited);//last row
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};