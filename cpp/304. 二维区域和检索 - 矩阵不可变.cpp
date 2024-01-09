class NumMatrix {
public:
    vector<vector<int> > preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(n == 0 || m == 0) return;
        preSum = vector<vector<int> >(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i-1][j-1] - preSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] -preSum[row2 + 1][col1] - preSum[row1][col2 + 1]+ preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */