class Solution {
public:
    void solve(string s,string &op,set<string> &ans){
        if(s.size()==0){
            ans.insert(op);
            return;
        }
        string op1=op;
        string op2=op;
        op1+=tolower(s[0]);
        op2+=toupper(s[0]);
        s.erase(s.begin()+0);

        solve(s,op1,ans);
        solve(s,op2,ans);
    }
    vector<string> letterCasePermutation(string s) {
        set<string> ans;
        string op="";
        solve(s,op,ans);
        vector<string> result(ans.begin(),ans.end());
        return result;
    }
};