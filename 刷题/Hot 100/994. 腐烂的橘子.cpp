class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int organges=0;
        queue<pair<int, int> > qu;
        int m=grid.size(), n=grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    organges++;
                } else if(grid[i][j] == 2) {
                    qu.push({i,j});
                }
            }
        }
        if(organges == 0) {
            return 0;
        }
        int t=0;
        while(!qu.empty()) {
            if(organges == 0) {
                return t;
            }
            int sz = qu.size();
            for(int i=0; i<sz; i++) {
                pair<int, int> cur = qu.front();
                qu.pop();
                grid[cur.first][cur.second]=3;
                for(int j=0; j<4; j++) {
                    int tx=dir[j][0] + cur.first;
                    int ty=dir[j][1] + cur.second;
                    if(tx<0 || tx>=m || ty<0 || ty>=n || grid[tx][ty] == 3) continue;
                    if(grid[tx][ty] == 1) {
                        organges--;
                        grid[tx][ty] = 3;
                    }
                    if(grid[tx][ty] != 0) {
                        qu.push({tx, ty});
                    }
                }
            }
            t++;
        }
        return -1;
    }
};