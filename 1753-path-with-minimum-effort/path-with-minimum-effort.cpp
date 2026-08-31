class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int n,m;
    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!pq.empty())
        {
            auto [effort,pos]=pq.top();
            int r=pos.first;
            int c=pos.second;
            pq.pop();
            if(r==n-1 && c==m-1) return effort;
            if(effort>dist[r][c]) continue;
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc)){
                    int newEffort=max(abs(grid[r][c]-grid[newr][newc]),effort);
                    if(newEffort<dist[newr][newc]){
                        dist[newr][newc]=newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};