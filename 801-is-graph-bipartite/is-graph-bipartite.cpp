class Solution {
public:
    bool bfs(int node, vector<vector<int>> &adj, vector<int>& color) {
        color[node]=0;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int root=q.front();
            q.pop();
            for(int neigh:adj[root]){
                if(color[neigh]!=-1 && color[neigh]==color[root]) return false;
                if(color[neigh]==-1){
                    color[neigh]=(color[root]+1)%2;
                    q.push(neigh);
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) { 
        int V=graph.size();
        vector<int> color(V,-1);
        for(int i = 0; i < V; i++) {
            if(color[i]==-1 && !bfs(i, graph, color)) {
                return false;
            }
        }
        return true;
    }
};