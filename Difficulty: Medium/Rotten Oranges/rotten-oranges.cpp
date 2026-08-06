class Solution {
  public:
    int r,c;
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    bool valid(int i,int j){
        return i>=0&&j>=0&&i<r&&j<c;
    }
    int orangesRot(vector<vector<int>>& hospital) {
        // code here
         r=hospital.size();
        c=hospital[0].size();
        int timer=0;
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==2)
                q.push({i,j});
                else if(hospital[i][j]==1)
                fresh++;
            }
        }
        if(fresh==0) return 0;
        while(!q.empty())
        {
            timer++;
            int curr=q.size();
            while(curr--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(valid(i+row[k],j+col[k])&&hospital[i+row[k]][j+col[k]]==1){
                        hospital[i+row[k]][j+col[k]]=2;
                        q.push({i+row[k],j+col[k]});
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==1)
                return -1;
            }
        }
        return timer-1;
    }
};