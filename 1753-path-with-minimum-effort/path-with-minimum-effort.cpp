class Solution {
public:
    int rows,cols;
    typedef pair<int,pair<int,int>> p;//{diff,{row,col}}
    bool isValid(int i,int j){
        return i>=0 && i<rows && j>=0 && j<cols;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        rows=heights.size();
        cols=heights[0].size();
        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==rows-1 && c==cols-1) return diff;
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