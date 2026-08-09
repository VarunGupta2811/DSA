class Solution {
  public:
    bool isValid(int adjr,int adjc,int n,int m){
        return adjr>=0 && adjr<n && adjc>=0 && adjc<m;
    }
    vector<int> parent;
    vector<int> size;
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    void Union(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        parent.resize(n*m);
        size.assign(n*m,1);
        for(int i=0;i<n*m;i++) parent[i]=i;
        int visit[n][m];
        memset(visit,0,sizeof(visit));
        int cnt=0;
        vector<int> ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(visit[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            visit[row][col]=1;
            cnt++;
            int dr[]={-1,0,1,0};//change in rows (up,right,down,left)
            int dc[]={0,1,0,-1};//change in columns (up,right,down,left)
            for(int ind=0;ind<4;ind++){
                int adjr=row+dr[ind];
                int adjc=col+dc[ind];
                if(isValid(adjr,adjc,n,m)){
                    if(visit[adjr][adjc]==1){
                        int node=row*m+col;
                        int adjNode=adjr*m+adjc;
                        if(find(node)!=find(adjNode)){
                            cnt--;
                            Union(node,adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
