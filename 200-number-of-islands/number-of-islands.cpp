class Solution {
public:

    vector<int> parent;
    vector<int> size;
    int find(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v) {

        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
            return;

        if(size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && r < n &&
               c >= 0 && c < m;
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        parent.resize(n * m);
        size.assign(n * m, 1);

        for(int i = 0; i < n * m; i++) {
            parent[i] = i;
        }

        int cnt = 0;

        for(int i = 0; i < n; i++) {
             for(int j = 0; j < m; j++) {
                 if(grid[i][j] == '1') {
                    cnt++;
                }
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(grid[row][col] == '0')
                    continue;
                int node = row * m + col;
                for(int ind = 0; ind < 4; ind++) {
                    int adjr = row + dr[ind];
                    int adjc = col + dc[ind];
                    if(isValid(adjr, adjc, n, m)) {
                        if(grid[adjr][adjc] == '1') {
                            int adjNode = adjr * m + adjc;
                            if(find(node) != find(adjNode)) {
                                cnt--;
                                Union(node, adjNode);
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};