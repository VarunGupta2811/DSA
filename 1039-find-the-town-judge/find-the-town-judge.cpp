class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        vector<int>Outdeg(n+1,0);
        vector<int>Indeg(n+1,0);
        for(vector<int> vec:trust){
            int u=vec[0];
            int v=vec[1];
            Outdeg[u]++;
            Indeg[v]++;
            adj[u].push_back(v);
        }
        for(int i=1;i<n+1;i++){
            if(Outdeg[i]==0 && Indeg[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};