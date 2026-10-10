class Solution {
public:
    void solve(vector<int> nums, set<vector<int>> &st, vector<int> temp){
        if(nums.size() == 0){
            st.insert(temp); 
            return;
        }
        vector<int> temp1 = temp;
        vector<int> temp2 = temp;
        
        temp2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);
        
        solve(nums, st, temp1);
        solve(nums, st, temp2);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> temp;
        solve(nums, st, temp);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};