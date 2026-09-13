class Solution {
public:
    int n,m;
    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void bfs(int r,int c,vector<vector<char>> &grid,vector<vector<bool>>&visited){
        visited[r][c]=true;
        queue<pair<int,int>>q;
        q.push({r,c});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty())
        {
            auto [row,col]=q.front();
            q.pop();
            for(int ind=0;ind<4;ind++){
                int newr=row+dr[ind];
                int newc=col+dc[ind];
                if(isValid(newr,newc) && grid[newr][newc]=='1' && !visited[newr][newc]){
                    q.push({newr,newc});
                    visited[newr][newc]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int count=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};