class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
      int n=image.size();
      int m=image[0].size();
      int orig=image[sr][sc];
      if(orig==newColor) return image;
      queue<pair<int,int>> q;
      q.push({sr,sc});
      image[sr][sc]=newColor;
      int dr[]={-1,0,1,0};
      int dc[]={0,-1,0,1};
      while(!q.empty())
      {
        auto [r,c]=q.front();
        q.pop();
        for(int ind=0;ind<4;ind++){
            int newr=r+dr[ind];
            int newc=c+dc[ind];
            if(isValid(newr,newc,n,m) && image[newr][newc]==orig){
                image[newr][newc]=newColor;
                q.push({newr,newc});
            }
        }
      }
      return image;
    }
};