class Solution {
public:
int n,m;
    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    grid[i][j]=0;
                }else{
                    grid[i][j]=-1;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc) &&  grid[newr][newc]==-1){
                    q.push({newr,newc});
                    grid[newr][newc]=grid[r][c]+1;
                }
            }
        }
        return grid;
    }
};