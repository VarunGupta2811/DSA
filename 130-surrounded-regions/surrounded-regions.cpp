class Solution {
public:
    int n,m;
    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void solve(vector<vector<char>>& mat) {
        n=mat.size();
       m=mat[0].size();
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||i==n-1||j==0||j==m-1){
                if(mat[i][j]=='O'){
                    q.push({i,j});
                    mat[i][j]='V';
                }
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
            if(isValid(newr,newc) && mat[newr][newc]=='O'){
                q.push({newr,newc});
                mat[newr][newc]='V';
            }
        }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='O'){
                mat[i][j]='X';
            }else if(mat[i][j]=='V'){
                mat[i][j]='O';
            }
        }
       }
    }
};