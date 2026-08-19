class Solution {
public:
    void dfs(int node,vector<vector<int>>& rooms,vector<bool> &visited){
        visited[node]=true;
        for(int adj:rooms[node]){
            if(!visited[adj]){
                dfs(adj,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        visited[0]=true;
        dfs(0,rooms,visited);
        for(bool v:visited){
            if(v==false) return false;
        }
        return true;
    }
};