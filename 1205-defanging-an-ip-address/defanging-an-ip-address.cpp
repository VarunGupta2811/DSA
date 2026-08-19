class Solution {
public:
    string defangIPaddr(string address) {
        string result="";
        for(char c:address){
            if(c=='.'){
                string temp="[.]";
                result+=temp;
            }else{
                result+=c;
            }
            
        }
        return result;
    }
};