class Solution {
public:
    string rotate(string &goal)
    {
        string res="";
        for(int i=1;i<goal.size();i++){
            res+=goal[i];
        }
        res+=goal[0];
        return res;
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size();
        int shift=0;
        while(shift<n)
        {
            if(s==goal) return true;
            goal=rotate(goal);
            shift++;
        }
        return false;
    }
};