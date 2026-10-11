class Solution {
public:
    void solve(string s, string &op, vector<string> &ans){
        if(s.size() == 0){
            ans.push_back(op);
            return;
        }
        if (isalpha(s[0])) {
            string op1 = op;
            string op2 = op;
            
            op1 += tolower(s[0]);
            op2 += toupper(s[0]);
            s.erase(s.begin() + 0);

            solve(s, op1, ans);
            solve(s, op2, ans);
        } 
        else {
            string op1 = op;
            op1 += s[0];
            s.erase(s.begin() + 0);
            solve(s, op1, ans);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string op = "";
        solve(s, op, ans);
        return ans;
    }
};