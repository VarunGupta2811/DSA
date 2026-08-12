class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
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
    bool isValid(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        parent.resize(n*n);
        size.assign(n*n,1);
        for(int i=0;i<n*n;i++) parent[i]=i;

        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                for(int ind=0;ind<4;ind++){
                    int newr=row +dr[ind];
                    int newc=col+dc[ind];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        Union(row*n+col,newr*n+newc);
                    }
                }
            }
        }
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                set<int> components;
                for(int ind=0;ind<4;ind++){
                    int newr=row+dr[ind];
                    int newc=col+dc[ind];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        components.insert(find(newr*n+newc));
                    }
                }
                int totalSize=0;
                for(auto it:components){
                    totalSize+=size[it];
                }
                ans=max(ans,totalSize+1);
            }
        }
        for(int cell=0;cell<n*n;cell++){
            ans=max(ans,size[find(cell)]);
        }
        return ans;
    }
};