class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool flag = false;
    int m, n;
    vector<vector<bool>> vis;
    void backtrack(vector<vector<char>>& board, string word, int ind, int x, int y) {
        if(ind == word.size()) {
            flag = true;
            return;
        } 
        vis[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if(tx >= m || tx < 0 || ty >= n || ty < 0 || word[ind] != board[tx][ty] || vis[tx][ty]) continue;
            vis[tx][ty] = true;
            backtrack(board, word, ind + 1, tx, ty);
            vis[tx][ty] = false;
        }
        vis[x][y] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    backtrack(board, word, 1, i, j);
                    if(flag) return true;
                }
            }
        }
        return flag;
    }
};