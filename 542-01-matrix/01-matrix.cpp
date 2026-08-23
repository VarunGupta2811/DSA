class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    pq.push({0,{i,j}});
                    ans[i][j]=0;
                }
            }
        }
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(isValid(newr,newc,m,n)){
                    if(ans[r][c]+1<ans[newr][newc]){
                        ans[newr][newc]=ans[r][c]+1;
                        pq.push({ans[newr][newc],{newr,newc}});
                    }
                }
            }
        }
        return ans;
    }
};