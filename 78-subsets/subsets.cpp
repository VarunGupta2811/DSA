class Solution {
public:
    void solve(vector<int> nums,vector<vector<int>> &ans,vector<int>& temp){
        if(nums.size()==0){
            ans.push_back(temp);
            return;
        }
        vector<int> temp1=temp;
        vector<int> temp2=temp;

        temp2.push_back(nums[0]);
        nums.erase(nums.begin()+0);

        solve(nums,ans,temp1);
        solve(nums,ans,temp2);

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums,ans,temp);
        return ans;
    }
};