class Solution {
public:
    vector<int>parent;
    vector<int> rank;
    int find(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=find(parent[node]);
    }
    void Union(int u,int v){
        int pu=find(u);
        int pv=find(v);
        
        if(pu==pv) return;
        
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        parent.resize(details.size());
        rank.assign(details.size(),0);
        
        for(int i=0;i<details.size();i++) parent[i]=i;
        
        unordered_map<string,int> mapmailNode;
        for(int i=0;i<details.size();i++){
            for(int j=1;j<details[i].size();j++){
                string mail=details[i][j];
                if(mapmailNode.find(mail)==mapmailNode.end()){
                    mapmailNode[mail]=i;
                }else{
                    Union(i,mapmailNode[mail]);
                }
            }
        }
        vector<string> mergedMail[details.size()];
        for(auto it:mapmailNode){
            string mail=it.first;
            int node=find(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        
        for(int i=0;i<details.size();i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};