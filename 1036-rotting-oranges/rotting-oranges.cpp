class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>res(m,vector<int>(n,-1));
        int count=0;
        queue<pair<int,int>>que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!que.empty())
        {
            int r=que.front().first;
            int c=que.front().second;
            que.pop();
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc,m,n) && res[newr][newc]==-1  && grid[newr][newc]==1){
                    res[newr][newc]=res[r][c]+1;
                    count=max(count,res[newr][newc]);
                    que.push({newr,newc});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(res[i][j]==-1 && grid[i][j]==1) return -1;
            }
        }
        return count;
    }
};