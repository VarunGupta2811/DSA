class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for(int i = 0, j = k; i < nums.size(); i++)
        {
            if(nums[i] == k)
            {
                k += j;
                i = -1;
            }
        }
        return k;
    }
};