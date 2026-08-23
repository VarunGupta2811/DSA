class Solution {
public:
    bool isValid(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int dist=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(isValid(newr,newc,m,n) && ans[newr][newc]==-1){
                    ans[newr][newc]=dist+1;
                    q.push({dist+1,{newr,newc}});
                }
            }
        }
        return ans;
    }
};