class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    bool isValid(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        vector<int> result(n*n,INT_MAX);
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({1,{0,0}});
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,-1,-1,-1,0,1,1,1};
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(dist>result[r*n+c]) continue;
            if(r==n-1 && c==n-1) return dist;
            for(int ind=0;ind<8;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc,n)&&grid[newr][newc]==0){
                   int adjNode=newr*n+newc;
                   if(dist+1<result[adjNode]){
                    result[adjNode]=dist+1;
                    pq.push({dist+1,{newr,newc}});
                   }
                }
            }
        }
        return -1;
    }
};