class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=nums.size();
        int neg=0,pos=0;
        for(int &v:nums){
            if(v==0) return 0;
            if(v>0) pos++;
            if(v<0) neg++;
        }
        if(neg%2==0) return 1;
        return -1;
    }
};