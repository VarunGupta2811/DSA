class Solution {
public:
    void dfs(vector<vector<int>>& graph, int currentNode, int target, vector<int>& currentPath, vector<vector<int>>& result){
        if(currentNode==target){
            result.push_back(currentPath);
            return;
        }
        for(int neighbour:graph[currentNode]){
            currentPath.push_back(neighbour);
            dfs(graph,neighbour,target,currentPath,result);
            currentPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> currentPath;

        int target=graph.size()-1;
        currentPath.push_back(0);
        dfs(graph,0,target,currentPath,result);
        return result;
    }
};