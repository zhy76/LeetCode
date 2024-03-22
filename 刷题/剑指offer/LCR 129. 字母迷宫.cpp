class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> used;
    bool backtrack(vector<vector<char>>& grid, string target, int ind, int x, int y) {
        // cout<<x<<y<<grid[x][y]<<ind<<target[ind]<<endl;
        if(ind == target.size() - 1) {
            return true;
        }
        for(int i = 0; i < 4; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= m || ty < 0 || ty >= n || used[tx][ty]) {
                continue;
            }
            if(grid[tx][ty] == target[ind + 1]) {
                used[tx][ty] = true;
                bool flag = backtrack(grid, target, ind + 1, tx, ty);
                if(flag) return true;
                used[tx][ty] = false;
            }
        }
        return false;
    }

    bool wordPuzzle(vector<vector<char>>& grid, string target) {
        m = grid.size(), n = grid[0].size();
        used.resize(m + 1, vector<bool>(n + 1, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == target[0]) {
                    // cout<<grid[i][j] << target[0]<<endl;
                    used[i][j] = true;
                    bool flag = backtrack(grid, target, 0, i, j);
                    used[i][j] = false;
                    if(flag) return flag;
                }
            }
        }
        return false;
    }
};