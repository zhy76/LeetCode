class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k > n / 2) {
            return maxProfitInf(prices);
        }
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(k+1, vector<int>(2, 0)));
        for(int i=0; i<n; i++) {
            dp[i][0][1] = -prices[i];
        }
        for(int i=0; i<n; i++) {
            for(int j=1; j<=k; j++) {
                if(i == 0) {
                    dp[i][j][1] = -prices[i];
                    continue;
                }
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
    int maxProfitInf(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int>(2, 0));
        for(int i=0; i<n; i++) {
            if(i == 0) {
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};