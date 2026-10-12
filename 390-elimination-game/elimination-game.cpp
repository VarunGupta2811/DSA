class Solution {
public:
    int lastRemaining(int n) {
        bool left=true;
        int head=1,step=1,remain=n;
        while(remain>1){
            if(left || remain%2!=0){
                head+=step;
            }
            step*=2;
            remain/=2;
            left=!left;
        }
        return head;
    }
};