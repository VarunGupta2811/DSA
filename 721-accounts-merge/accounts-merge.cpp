class Solution {
public:
    vector<int> parent;
    vector<int> size;
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

        if(size[pu]>size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n);
        size.assign(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }else{
                    Union(i,mp[mail]);
                }
            }
        }
        vector<string> merged[n];
        for(auto it:mp){
            string mail=it.first;
            int node=find(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};