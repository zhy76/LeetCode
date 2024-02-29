class Solution {
public:
    int ans = 0;
    bool isValid(int row, int col, vector<vector<int> > board){
        int n=board[row].size();
        for(int i=0; i<n; i++) {
            if(board[i][col] == 1) return false;
        }
        for (int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 1) return false;
        }
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 1) return false;
        }
        return true;
    }
    void backtrack(int row, int n, vector<vector<int> > board){
        if(row == n) {
            ans++;
            return;
        }
        for(int j=0; j<n; j++) {
            if(!isValid(row, j, board)) {
                continue;
            }
            board[row][j] = 1;
            backtrack(row+1, n, board);
            board[row][j] = 0;
        }
    }
    int totalNQueens(int n) {
        vector<vector<int> > board(n, vector<int>(n,0));
        backtrack(0, n, board);
        return ans;
    }
};