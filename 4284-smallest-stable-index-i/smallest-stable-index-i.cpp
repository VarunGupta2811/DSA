class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxVal=INT_MIN;
        for(int i=0;i<n;i++){
            maxVal=max(nums[i],maxVal);
            int minVal=INT_MAX;
            for(int j=i;j<n;j++){
                minVal=min(nums[j],minVal);
            }
            if(maxVal-minVal<=k){
                    return i;
            }
        }
        return -1;
    }
};