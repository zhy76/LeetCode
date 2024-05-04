class Solution {
public:
    vector<int> father;
    int findFather(int x) {
        if(father[x] != x) father[x] = findFather(father[x]);
        return father[x];
    }
    void Union(int x, int y) {
        int fx = findFather(x);
        int fy = findFather(y);
        if(fx != fy) {
            father[fx] = fy;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        father = vector<int>(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            father[i] = i;
        }
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            if(findFather(x) != findFather(y)) {
                Union(x, y);
            } else {
                return edge;
            }
        }
        return vector<int>{};
    }
};