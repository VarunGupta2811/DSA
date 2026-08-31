class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> Indeg(n,0);

        queue<int> q;
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int num:graph[i]){
                adj[num].push_back(i);
                Indeg[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(Indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int &adjNode:adj[node]){
                Indeg[adjNode]--;
                if(Indeg[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};