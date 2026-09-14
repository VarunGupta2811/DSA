class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int>& color,int curr) {
        color[node]=curr;
        for(int neigh:graph[node])
        {
            if(color[neigh]!=-1 && color[neigh]==color[node]) return false;
            if(color[neigh]==-1){
                if(!dfs(neigh,graph,color,(color[node]+1)%2)){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) { 
        int V=graph.size();
        vector<int> color(V,-1);
        for(int i = 0; i < V; i++) {
            if(color[i]==-1 && !dfs(i, graph, color,0)) {
                return false;
            }
        }
        return true;
    }
};