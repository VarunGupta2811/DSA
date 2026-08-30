class Solution {
public:
    int n;
    typedef pair<int,pair<int,int>>p;
    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
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
            auto [r,c]=q.front();
            q.pop();
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc) && dist[newr][newc]==INT_MAX){
                    dist[newr][newc]=dist[r][c]+1;
                    q.push({newr,newc});
                }
            }
        }
        priority_queue<p>pq;
        vector<vector<int>>safe(n,vector<int>(n,-1));
        safe[0][0]=dist[0][0];
        pq.push({dist[0][0],{0,0}});
        while(!pq.empty())
        {
            auto [fact,pos]=pq.top();
            int r=pos.first;
            int c=pos.second;
            pq.pop();
            if(r==n-1 && c==n-1) return fact;
            if(fact<safe[r][c]) continue;
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc)){
                    int newFact=min(fact,dist[newr][newc]);
                    if(newFact>safe[newr][newc]){
                        safe[newr][newc]=newFact;
                        pq.push({newFact,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};