class Solution {
public:
    void solve(vector<int> nums,vector<int> &temp,set<vector<int>> &st){
        if(nums.size()==0){
            st.insert(temp);
            return;
        }
        vector<int> temp1=temp;
        vector<int> temp2=temp;
        temp2.push_back(nums[0]);
        nums.erase(nums.begin()+0);

        solve(nums,temp1,st);
        solve(nums,temp2,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int> temp;
        solve(nums,temp,st);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};