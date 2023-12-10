class Solution {
public:
    vector<vector<string>> res;
    bool isValid(vector<string> strs, int x, int y, int n){
        for(int i=0; i<=x; i++) {
            if(strs[i][y] == 'Q') {
                return false;
            }
        }
        for(int i=x-1,j=y+1; i>=0 && j<n; i--, j++){
            if(strs[i][j] == 'Q') {
                return false;
            }
        }
        for(int i=x-1,j=y-1; i>=0 && j>=0; i--, j--) {
            if(strs[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void backtrack(int row, int n, vector<string>& track){
        if(row == n) {
            res.push_back(track);
            return;
        }
        for(int j=0;j<n;j++){
            if(!isValid(track, row, j, n)){
                continue;
            }
            track[row][j] = 'Q';
            backtrack(row+1, n, track);
            track[row][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n, string(n, '.'));
        backtrack(0, n, s);
        return res;
    }
};