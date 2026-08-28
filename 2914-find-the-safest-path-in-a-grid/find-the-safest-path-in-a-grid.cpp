class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    bool isValid(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] ==1 || grid[n-1][n-1]==1) return 0;
        priority_queue<p>pq;
        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc,n) && dist[newr][newc]==INT_MAX){
                   dist[newr][newc]=dist[r][c]+1;
                   q.push({newr,newc});
                }
            }
        }
         vector<vector<int>>best(n,vector<int>(n,-1));
         best[0][0]=dist[0][0];
         pq.push({dist[0][0],{0,0}});
         while(!pq.empty())
         {
            int fact=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==n-1) return fact;
            if(fact<best[r][c]) continue;
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc,n)){
                    int newFact=min(dist[newr][newc],fact);
                    if(newFact>best[newr][newc]){
                        best[newr][newc]=newFact;
                        pq.push({newFact,{newr,newc}});
                    }
                }
            }
         }
         return 0;
    }
};