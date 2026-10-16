class Solution {
public:
    void solve(vector<int> nums,vector<int>& op,set<vector<int>>&st){
        if(nums.size()==0){
            st.insert(op);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int> sub1(nums.begin(),nums.begin()+i);
            vector<int> sub2(nums.begin()+i+1,nums.end());
            vector<int> newIp=sub1;
            newIp.insert(newIp.end(),sub2.begin(),sub2.end());
            vector<int> newOp=op;
            newOp.push_back(nums[i]);
            solve(newIp,newOp,st);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> op;
        solve(nums,op,st);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};