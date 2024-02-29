class Solution {
public:
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int n, m;
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '2';
        for(int i=0; i<4; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx<n && tx>=0 && ty<m && ty>=0 && grid[tx][ty] == '1') {
                dfs(grid, tx, ty);
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};