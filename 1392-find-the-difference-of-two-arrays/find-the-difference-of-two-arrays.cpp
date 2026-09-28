class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>unique1;
        vector<int>unique2;
        for(int i = 0; i < nums1.size(); i++) {
            bool isDuplicate = false;
            for(int j = 0; j < unique1.size(); j++) {
                if(nums1[i] == unique1[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if(!isDuplicate) {
                unique1.push_back(nums1[i]);
            }
        }
        for(int i = 0; i < nums2.size(); i++) {
            bool isDuplicate = false;
            for(int j = 0; j < unique2.size(); j++) {
                if(nums2[i] == unique2[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if(!isDuplicate) {
                unique2.push_back(nums2[i]);
            }
        }
        vector<int> v1;
        for(int i = 0; i < unique1.size(); i++) {
            bool found = false;
            for(int j = 0; j < unique2.size(); j++) {
                if(unique1[i] == unique2[j]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                v1.push_back(unique1[i]);
            }
        }
        vector<int> v2;
        for(int i = 0; i < unique2.size(); i++) {
            bool found = false;
            for(int j = 0; j < unique1.size(); j++) {
                if(unique2[i] == unique1[j]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                v2.push_back(unique2[i]);
            }
        }
        return {v1, v2};
    }
};