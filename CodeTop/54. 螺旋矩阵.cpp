class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n-1, top = 0, low = m-1;
        vector<int> res;
        while(res.size() < m*n) {
            if(left <= right && top <= low) {
                for(int i=left; i<=right; i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if(left <= right && top <= low) {
                for(int i=top; i<=low; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(left <= right && top <= low) {
                for(int i=right; i>=left; i--) {
                    res.push_back(matrix[low][i]);
                }
                low--;
            }
            if(left <= right && top <= low) {
                for(int i=low; i>=top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};