class Solution {
public:
bool isValid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int countOne=0;
       vector<vector<bool>>visited(n,vector<bool>(m,false));
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
                visited[i][j]=true;
            }
            else if(grid[i][j]==1){
                countOne++;
            }
        }
       }
       if(countOne==0) return 0;
       int dr[]={-1,0,1,0};
       int dc[]={0,-1,0,1};
       int timer=0;
       while(!q.empty())
       {
        int p=q.size();
        while(p--){
            auto [r,c]=q.front();
            q.pop();
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc,n,m) && grid[newr][newc]==1 && !visited[newr][newc]){
                    visited[newr][newc]=true;
                    q.push({newr,newc});
                }
            }
        }
        timer++;
    }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]==1) return -1;
        }
       }
       return timer-1;
    }
};