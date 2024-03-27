class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size(), n = frame[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i >= 1) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(j >= 1) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] += frame[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};