class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while(i >= 0 && j <= n-1) {
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] < target) {
                j++;
            } else {
                i--;
            }
        }   
        return false;
    }
};