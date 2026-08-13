class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int u) {
        if (u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    int maxRemove(vector<vector<int>>& stones) {

        int n = stones.size();

        // Every stone is initially its own component
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Connect stones having same row or same column
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    Union(i, j);
                }
            }
        }

        // Count connected components
        int components = 0;

        for (int i = 0; i < n; i++) {

            if (find(i) == i) {
                components++;
            }
        }

        return n - components;
    }
};