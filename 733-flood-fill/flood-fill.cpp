class Solution {
public:
    typedef pair<int,int> p;
    int n,m;
    bool isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size();
        m=image[0].size();
        queue<p> q;
        q.push({sr,sc});
        int orig=image[sr][sc];
        if(orig==color) return image;
        image[sr][sc]=color;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(isValid(newr,newc) && image[newr][newc]==orig){
                    image[newr][newc]=color;
                    q.push({newr,newc});
                }
            }
        }
        return image;
    }
};