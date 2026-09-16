class Solution {
public:
int targetNode;
    void dfs(int node,vector<int> &currPath,vector<vector<int>>&graph,vector<vector<int>>&result){
        if(node==targetNode){
            result.push_back(currPath);
            return;
        }
        for(int neigh:graph[node]){
            currPath.push_back(neigh);
            dfs(neigh,currPath,graph,result);
            currPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        targetNode=graph.size()-1;
        vector<vector<int>> result;
        vector<int> currPath;
        currPath.push_back(0);
        dfs(0,currPath,graph,result);
        return result;
    }
};