class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        int dir = 1;
        int i = 0, j = 0;
        while(res.size() < m*n) {
            res.push_back(mat[i][j]);
            if(dir) {
                int x = i - 1;
                int y = j + 1;
                if(x < 0 || y >= n) {
                    dir = 0;
                    if(j + 1 < n) {
                        j = j+1;
                    } else {
                        i = i + 1;
                    }
                    continue;
                }
                i = x;
                j = y;
            } else {
                int x = i + 1;
                int y = j - 1;
                if(x >= m || y < 0) {
                    dir = 1;
                    if(i + 1 < m) {
                        i = i + 1;
                    } else {
                        j = j + 1;
                    }
                    continue;
                }
                i = x;
                j = y;
            }
        }
        return res;
    }
};