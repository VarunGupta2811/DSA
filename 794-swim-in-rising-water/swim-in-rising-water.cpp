class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
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
    bool isValid(int newr,int newj,int n){
        return newr>=0 && newr<n && newj>=0 && newj<n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int total=n*n;
        parent.resize(total);
        size.assign(total,1);
        for(int i=0;i<total;i++) parent[i]=i;

        vector<pair<int,int>> pos(total);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                pos[grid[r][c]] = {r, c};
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int t=0;t<total;t++){
            int r=pos[t].first;
            int c=pos[t].second;
            visited[r][c]=true;

            for(int ind=0;ind<4;ind++){
                int newr=r+dr[ind];
                int newc=c+dc[ind];

                if(isValid(newr,newc,n) && visited[newr][newc]){
                    Union(r*n+c,newr*n+newc);
                }
            }
            if(find(0)==find(total-1)) return t;
        }
        return -1;
    }
};