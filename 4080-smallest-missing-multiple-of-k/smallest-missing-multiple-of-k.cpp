class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        int maxVal=nums[0];
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            maxVal=max(maxVal,nums[i]);
            mp[nums[i]]=true;
        }
        int i=k;
        for(;i<=maxVal;i+=k){
            if(mp[i]==false) return i;
        }
        return i;
    }
};