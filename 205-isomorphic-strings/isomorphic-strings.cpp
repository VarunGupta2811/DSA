class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpS;
       unordered_map<char,char>mpT;
       for(int i=0;i<s.size();i++){
        char ch1=s[i];
        char ch2=t[i];
        if(mpS.find(ch1)!=mpS.end() && mpS[ch1]!=ch2 || 
        mpT.find(ch2)!=mpT.end() && mpT[ch2]!=ch1){
            return false;
        }
        mpS[ch1]=ch2;
        mpT[ch2]=ch1;
       }
        return true;
    }
};