class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    int n,m;
    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!pq.empty())
        {
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(diff>dist[r][c]) continue;
            if(r==n-1 && c==m-1) return diff;
            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc)){
                    int newEffort=max(abs(heights[r][c]-heights[newr][newc]),diff);
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