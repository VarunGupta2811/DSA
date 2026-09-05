class Solution {
public:
    void dfs(int curr,int target,vector<vector<int>>& graph,vector<int> &currPath,vector<vector<int>> &result){
        if(curr==target){
            result.push_back(currPath);
            return;
        }
        for(int neigh:graph[curr]){
            currPath.push_back(neigh);
            dfs(neigh,target,graph,currPath,result);
            currPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> result;
        vector<int> currPath;
        currPath.push_back(0);
        dfs(0,n-1,graph,currPath,result);
        return result;
    }
};