class Solution {
public:
    bool isValid(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0]=2;

        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,-1,-1,-1,0,1,1,1};

        while(!q.empty())
        {
            int dist=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            if(r==n-1 && c==n-1) return dist;
            q.pop();

            for(int ind=0;ind<8;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];
                if(isValid(newr,newc,n) && grid[newr][newc]==0){
                    grid[newr][newc]=2;
                    q.push({dist + 1, {newr, newc}});
                }
            }
        }
        return -1;
    }
};