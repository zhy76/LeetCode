class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if(array.size() == 0)return vector<int>();
        int m = array.size(), n = array[0].size();
        int left = 0, right = n - 1, top = 0, low = m - 1;
        vector<int> res;
        while(res.size() < m*n) {
            if(left <= right && top <= low) {
                for(int i = left; i <= right; i++) {
                    res.push_back(array[top][i]);
                }
                top++;
            }
            
            if(left <= right && top <= low) {
                for(int i = top; i <= low; i++) {
                    res.push_back(array[i][right]);
                }
                right--;
            }
            
            if(left <= right && top <= low) {
                for(int i = right; i >= left; i--) {
                    res.push_back(array[low][i]);
                }
                low--;
            }
            
            if(left <= right && top <= low) {
                for(int i = low; i >= top; i--) {
                    res.push_back(array[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};