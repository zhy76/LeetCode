class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        int upper = 0, lower = n-1, left = 0, right = n-1;
        int x = 1;
        while(x <= n*n) {
            if(upper <= lower) {
                for(int i=left; i<=right; i++) {
                    matrix[upper][i] = x++;
                }
                upper++;
            }
            if(left <= right) {
                for(int i=upper; i<=lower; i++) {
                    matrix[i][right] = x++;
                }
                right--;
            }
            if(upper <= lower) {
                for(int i=right; i>=left; i--){
                    matrix[lower][i] = x++;
                }
                lower--;
            }
            if(left <= right) {
                for(int i=lower; i>=upper; i--) {
                    matrix[i][left] = x++;
                }
                left++;
            }
        }
        return matrix;
    }
};