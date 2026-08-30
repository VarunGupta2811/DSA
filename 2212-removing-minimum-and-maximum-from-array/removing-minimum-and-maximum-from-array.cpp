class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int maxVal=0;
        int minVal=0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[minVal]) minVal=i;
            if(nums[i]>nums[maxVal]) maxVal=i;
        }
        int largest=max(minVal,maxVal);
        int smallest=min(minVal,maxVal);
        int deleteFront = largest + 1;
        int deleteBack = n - smallest;
        int deleteBoth = (smallest + 1) + (n - largest);
        
        return min({deleteFront, deleteBack, deleteBoth});
    }
};