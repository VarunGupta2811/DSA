class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find(parent[node]);
    }
    void Union(int u,int v,int &extraEdges){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            extraEdges++;
            return;
        }
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        size.assign(n,1);

        for(int i=0;i<n;i++) parent[i]=i;

        int extraEdges=0;
        for(vector<int>&vec:connections){
            Union(vec[0],vec[1],extraEdges);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==parent[i]) ans++;
        }
        if(extraEdges>=ans-1){
            return ans-1;
        }else{
            return -1;
        }
    }
};