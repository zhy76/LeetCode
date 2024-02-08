class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int> > qu;
        int num = 0;
        int inqueue = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    qu.push({i, j});
                    num++;
                    inqueue++;
                } else if(grid[i][j] == 1) {
                    num++;
                }
            }
        }
        int t = 0;
        while(!qu.empty()) {
            if(inqueue == num) {
                break;
            }
            int sz = qu.size();
            for(int i=0; i<sz; i++) {
                auto cur = qu.front();
                qu.pop();
                int x = cur.first;
                int y = cur.second;
                for(int i = 0; i < 4; i++) {
                    int tx = x + dir[i][0];
                    int ty = y + dir[i][1];
                    if(tx >= m || tx < 0 || ty >= n || ty < 0 || grid[tx][ty] != 1) {
                        continue;
                    }
                    grid[tx][ty] = 2;
                    qu.push({tx,ty});
                    inqueue++;
                }
            }
            t++;
        }
        return inqueue == num ? t: -1;
    }
};