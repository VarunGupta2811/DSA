class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
        // code here
        unordered_set<string> st(words.begin(),words.end());
        if(st.find(e)==st.end()) return 0;
        queue<pair<string,int>>q;
        q.push({s,1});
        st.erase(s);
        while(!q.empty())
        {
            auto [word,steps]=q.front();
            q.pop();
            if(word==e) return steps;
            for(int i=0;i<word.size();i++)
            {
                char orig=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
    }
};