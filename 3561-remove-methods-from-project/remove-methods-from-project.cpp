class Solution {
public:
    void dfs(vector<int> adj[],int node,vector<bool>&visited,vector<int>&Indeg){
        visited[node]=true;
        for(int &v:adj[node]){
            Indeg[v]--;
            if(!visited[v]){
                dfs(adj,v,visited,Indeg);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> visited(n,0);
        vector<int> adj[n];
        vector<int>Indeg(n,0);

        for(vector<int>&vec:invocations){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            Indeg[v]++;
        }

        dfs(adj,k,visited,Indeg);
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i]=i;
        vector<int> result;
        for(int i=0;i<n;i++){
            if(visited[i] && Indeg[i]!=0){
                return ans;
            }else{
                if(!visited[i]){
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};