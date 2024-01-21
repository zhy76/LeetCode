class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(3, vector<int>(2, 0)));
        for(int i=0; i<n; i++) {
            dp[i][0][1] = -prices[i];
        }
        for(int i=0; i<n; i++) {
            for(int k=1; k<=2; k++) {
                if(i == 0) {
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }
        return dp[n-1][2][0];
    }
};