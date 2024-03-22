class Solution {
public:
    int digit(int x) {
        int sum = 0;
        while(x) {
            sum += (x % 10);
            x /= 10;
        }
        return sum;
    }
    vector<vector<bool> > used;
    int res = 0;
    int dir[2][2] = {{1, 0}, {0, 1}};
    void dfs(int m, int n, int cnt, int x, int y) {
        if(digit(x) + digit(y) <= cnt) {
            res++;
        } else return;
        for(int i = 0; i < 2; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx < 0 || tx >= m || ty < 0 || ty >= n || used[tx][ty]) {
                continue;
            }
            used[tx][ty] = true;
            dfs(m, n, cnt, tx, ty);
        }
    }
    int wardrobeFinishing(int m, int n, int cnt) {
        used.resize(m, vector<bool>(n, false));
        used[0][0] = true;
        dfs(m, n, cnt, 0, 0);
        return res;
    }
};