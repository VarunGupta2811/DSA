class Solution {
public:
    void solve(vector<int> &nums,int start,vector<vector<int>> &ans){
        if(start==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=start;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                swap(nums[start],nums[i]);
                solve(nums,start+1,ans);
                swap(nums[start],nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};