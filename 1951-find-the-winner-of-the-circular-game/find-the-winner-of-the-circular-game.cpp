class Solution {
public:
    void solve(vector<int> &arr,int k,int index,int &ans){
        if(arr.size()==1){
           ans=arr[0];
           return;
        }
        index=(index+k)%arr.size();
        arr.erase(arr.begin()+index);
        
        solve(arr,k,index,ans);
    }
    int findTheWinner(int n, int k) {
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        int index=0;
        k--;
        int ans=-1;
        solve(arr,k,index,ans);
        return ans;
    }
};