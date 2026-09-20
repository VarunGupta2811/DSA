class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int prod=('z'-ch+1)*(i+1);
            sum+=prod;
        }
        return sum;
    }
};