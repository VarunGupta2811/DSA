class Solution {
public:
    typedef pair<int,int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<p> adj[n+1];
        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int> result(n+1,INT_MAX);
        result[k]=0;
        pq.push({0,k});
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
        for(int i=1;i<=n;i++){
            if(result[i]==INT_MAX) return -1;
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,result[i]);
        }
        return ans;
    }
};