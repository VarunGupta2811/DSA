class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void Union(int u,int v){
        int pu=find(u);
        int pv=find(v);

        if(pu==pv) return;

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        for(int i=0;i<isConnected.size();i++){
            parent.push_back(i);
            size.push_back(1);
        }
        for(int u=0;u<isConnected.size();u++){
            for(int v=0;v<isConnected.size();v++){
                if(isConnected[u][v] == 1 && u != v){
                    Union(u,v);
                }
            }
        }
        int count=0;
        for(int i=0;i<parent.size();i++){
            if(i==parent[i]) count++;
        }
        return count;
    }
};