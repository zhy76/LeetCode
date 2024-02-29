class Solution {
public:
    int res = 0;
    vector<string> board;
    unordered_map<int, bool> colcheck;
    unordered_map<int, bool> xiecheck1;
    unordered_map<int, bool> xiecheck2;
    void backtrack(int n, int row) {
        if(row == n) {
            res++;
            return;
        }
        for(int col = 0; col < n; col++) {
            if(colcheck[col]) continue;
            if(xiecheck1[row - col]) continue;
            if(xiecheck2[row + col]) continue;
            board[row][col] = 'Q';
            colcheck[col] = true;
            xiecheck1[row - col] = true;
            xiecheck2[row + col] = true;
            backtrack(n, row+1);
            board[row][col] = '.';
            colcheck[col] = false;
            xiecheck1[row - col] = false;
            xiecheck2[row + col] = false;
        }
    }
    int totalNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        backtrack(n, 0);
        return res;
    }
};