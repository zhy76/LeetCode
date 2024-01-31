class Solution {
public:
    vector<bool> vis;
    int res=0;
    int n;
    void dfs(int x, vector<vector<int> > isConnected) {
        vis[x] = true;
        for(int i=0; i<n; i++) {
            if(vis[i] || isConnected[x][i] == 0) continue;
            dfs(i, isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vis = vector<bool>(n, false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                res++;
                dfs(i, isConnected);
            }
        }
        return res;
    }
};