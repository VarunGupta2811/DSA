class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&visited){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(visited[i][j] || grid[i][j]==0) return;
        visited[i][j]=true;
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid,visited);
            }
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid,visited);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid,visited);
            }
            if(grid[n-1][j]==1){
                dfs(n-1,j,grid,visited);
            }
        }
        int enclaves=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1) enclaves++;
            }
        }
        return enclaves;
    }
};