class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        int fresh=0;
        queue<pair<int,int>>que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!que.empty())
        {
            int size=que.size();
            while(size--){
                int r=que.front().first;
                int c=que.front().second;
                que.pop();
                for(int ind=0;ind<4;ind++){
                    int newr=r+dr[ind];
                    int newc=c+dc[ind];
                    if(isValid(newr,newc,m,n) && grid[newr][newc]==1){
                        grid[newr][newc]=2;
                        que.push({newr,newc});
                        fresh--;
                    }
                }
            }
            count++;
        }
        return fresh==0?count-1:-1;
    }
};