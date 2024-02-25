class Solution {
public:
    int dir[4][2] = {{1, 0}, {0,1}, {-1,0}, {0, -1}};
    int res;
    int m = 0, n = 0;
    int sum = 0;
    void dfs(int x, int y, vector<vector<int>>& grid) {
        for(int i = 0; i < 4; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= m || ty < 0 || ty >= n || grid[tx][ty] == 0 || grid[tx][ty] == 2) {
                continue;
            }
            grid[tx][ty] = 2;
            sum++;
            dfs(tx, ty, grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 2;
                    sum = 1;
                    dfs(i, j, grid);
                    res = max(res, sum);
                }
            }
        }
        return res;
    }
};