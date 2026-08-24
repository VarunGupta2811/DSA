class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    pq.push({0,{i,j}});
                    dist[i][j]=0;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(wt>dist[r][c]) continue;
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc,m,n) && grid[newr][newc]==1){
                    if(wt+1<dist[newr][newc]){
                        dist[newr][newc]=wt+1;
                        pq.push({wt+1,{newr,newc}});
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]==INT_MAX && grid[i][j]==1) return -1;
                if(grid[i][j]==1){
                    ans=max(ans,dist[i][j]);
                }
            }
        }
        return ans;
    }
};