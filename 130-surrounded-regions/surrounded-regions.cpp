class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
       int m=mat[0].size();
       queue<pair<int,int>> q;
       //upper row
       for(int j=0;j<m;j++){
            if(mat[0][j]=='O'){
                mat[0][j]='Y';
                q.push({0,j});
            }
       }
       //bottom row
       for(int j=0;j<m;j++){
        if(mat[n-1][j]=='O'){
            mat[n-1][j]='Y';
            q.push({n-1,j});
        }
       }
       //first column
       for(int i=0;i<n;i++){
        if(mat[i][0]=='O'){
            mat[i][0]='Y';
            q.push({i,0});
        }
       }
        //last column
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O'){
                mat[i][m-1]='Y';
                q.push({i,m-1});
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
                if(isValid(newr,newc,n,m) && mat[newr][newc]=='O'){
                    mat[newr][newc]='Y';
                    q.push({newr,newc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O'){
                    mat[i][j]='X';
                }else if(mat[i][j]=='Y'){
                    mat[i][j]='O';
                }
            }
        }
    }
};