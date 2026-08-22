class Solution {
  public:
    typedef pair<int,int> p;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> result(V,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dist>result[node]) continue;
            for(auto &vec:adj[node]){
                int adjNode=vec.first;
                int wt=vec.second;
                if(dist+wt<result[adjNode]){
                    result[adjNode]=dist+wt;
                    pq.push({dist+wt,adjNode});
                }
            }
        }
        return result;
    }
};