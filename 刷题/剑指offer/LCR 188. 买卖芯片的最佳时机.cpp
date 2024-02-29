class Solution {
public:
    int bestTiming(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int> > dp(n, vector<int>(2, 0));
        for(int i=0; i<n; i++) {
            if(i - 1 == -1) {
                dp[i][0] = 0;
                dp[i][1] = -prices[0];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], - prices[i]);
        }
        return dp[n-1][0];
    }
};