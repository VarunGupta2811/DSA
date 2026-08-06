class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int ans=1;
            while(num>0){
                int last=num%10;
                ans*=last;
                num/=10;
            }
            if(ans%t==0) break;
            n++;
            num=n;
        }
        return n;
    }
};