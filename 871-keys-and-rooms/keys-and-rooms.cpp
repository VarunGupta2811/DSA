class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int adj:rooms[node]){
                if(!visited[adj]){
                    visited[adj]=true;
                    q.push(adj);
                }
            }
        }
        for(bool v:visited){
            if(v==false) return false;
        }
        return true;
    }
};