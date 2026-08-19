class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int num=x;
        int rev=0;
        while(num>0){
            int last=num%10;
            if(rev>INT_MAX/10) return 0;
            num/=10;
            rev=rev*10+last;
        }
        return rev==x;
    }
};