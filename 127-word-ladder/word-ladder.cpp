class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        queue<pair<string,int>>q;
        q.push({startWord,1});
        while(!q.empty())
        {
            auto [word,step]=q.front();
            q.pop();
            if(word==targetWord) return step;
            for(int i=0;i<word.size();i++){
                char orig=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
    }
};