class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    //    for(int i =0; i<nums.size(); i++){
    //     for(int j=i+1; j<nums.size(); j++){
    //         if(nums[i]+nums[j]== target){
    //             return{i,j};
    //         }
    //     }
    //    }
    //    return {};
    map<int, int>mpp;

    for(int i=0; i<nums.size(); i++){
        int current = nums[i];
        int more =  target - nums[i];
            if(mpp.find(more) != mpp.end()){
                return{mpp[more],i };
            }
            mpp[nums[i]] = i;
            }

            return {};
       }
       
};