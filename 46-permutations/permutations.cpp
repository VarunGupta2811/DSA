class Solution {
public:
    void solve(vector<int> nums,vector<int> &op,vector<vector<int>>& ans){
        if(nums.size()==0){
            ans.push_back(op);
            return;
        }
        for(int i=0;i<nums.size();i++){
            vector<int> sub1(nums.begin(),nums.begin()+i);
            vector<int> sub2(nums.begin()+i+1,nums.end());
            vector<int> newIp=sub1;
            newIp.insert(newIp.end(),sub2.begin(),sub2.end());
            vector<int> newOp=op;
            newOp.push_back(nums[i]);
            solve(newIp,newOp,ans);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(nums,op,ans);
        return ans;
    }
};