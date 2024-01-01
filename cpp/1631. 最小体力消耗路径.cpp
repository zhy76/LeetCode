class Solution {
private:
    struct State {
        int x;
        int y;
        int dis;
        State(int x, int y, int dis) {
            this->x = x;
            this->y = y;
            this->dis = dis;
        }
        friend bool operator < (State x, State y) {
            return x.dis > y.dis;
        }
    };
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int> > d(m, vector<int>(n, INT_MAX));
        vector<vector<bool> > vis(m, vector<bool>(n, false));
        priority_queue<State> qu;
        d[0][0] = 0;
        qu.push(State(0,0,0));
        while(!qu.empty()) {
            State cur = qu.top();
            qu.pop();
            int cur_x = cur.x;
            int cur_y = cur.y;
            int cur_dis = cur.dis;
            if(cur_x == m-1 && cur_y == n-1) {
                return cur_dis;
            }
            if(vis[cur_x][cur_y]) {
                continue;
            }
            vis[cur_x][cur_y] = true;
            for(int i=0; i<4; i++) {
                int tx = cur_x + dir[i][0];
                int ty = cur_y + dir[i][1];
                if(tx < 0 || tx >= m || ty < 0 || ty >= n) {
                    continue;
                }
                int tdis = max(d[cur_x][cur_y],abs(heights[cur_x][cur_y] - heights[tx][ty]));
                if(tdis < d[tx][ty]) {
                    d[tx][ty] = tdis;
                    qu.push(State(tx,ty,tdis));
                }
            }
        }
        return d[m-1][n-1];
    }
};