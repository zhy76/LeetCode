class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;
        int upper = 0, lower = n-1, left = 0, right = m-1;
        while(res.size() < m*n) {
            if(upper <= lower) {
                for(int i=left; i<=right; i++) {
                    res.push_back(matrix[upper][i]);
                }
                upper++;
            }
            if(left <= right) {
                for(int i=upper; i<=lower; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(upper<=lower) {
                for(int i=right; i>=left; i--) {
                    res.push_back(matrix[lower][i]);
                }
                lower--;
            }
            if(left <= right) {
                for(int i=lower; i>=upper; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};