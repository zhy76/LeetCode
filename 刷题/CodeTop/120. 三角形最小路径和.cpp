class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1) return triangle[0][0];
        // dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1])
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        // dp[1][0] = triangle[1][0] + dp[0][0];
        // dp[1][1] = triangle[1][1] + dp[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = i; j >=0; j--) {
                if(j == 0) {
                    dp[j] = triangle[i][j] + dp[j];
                } else if(j == i){
                    dp[j] = triangle[i][j] + dp[j-1];
                } else {
                    dp[j] = triangle[i][j] + min(dp[j], dp[j-1]);
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};