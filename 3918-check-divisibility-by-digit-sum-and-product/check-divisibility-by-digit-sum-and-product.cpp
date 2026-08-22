class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,x=n;
        long long prod=1;
        while(x>0)
        {
            int last=x%10;
            sum+=last;
            prod*=last;
            x/=10;
        }
        return n%(sum+prod)==0;
    }
};