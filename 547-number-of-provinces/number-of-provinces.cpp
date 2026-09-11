class Solution {
public:
    int n;
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node]=true;
        for(int j=0;j<n;j++){
            if(adj[node][j]==1 && !visited[j]){
                dfs(j,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
       n=adj.size();
       vector<bool> visited(n,false);
       int count=0;
       for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited);
            count++;
        }
       }
       return count;
    }
};