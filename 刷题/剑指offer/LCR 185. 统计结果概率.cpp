class Solution {
public:
    vector<double> statisticsProbability(int num) {
        // dp[i][k]:前i个骰子点数和为k的概率
        // dp[i][k] = sum(dp[i-1][k-j])(1<=j<=6)
        vector<vector<double> > dp(num + 1, vector<double>(6 * num + 1));
        for(int i = 0; i<=6; i++) {
            dp[1][i] = 1 / 6.0;
        }
        for(int i=2; i<=num; i++) {
            for(int k = i; k<=i*6; k++) {
                for(int j = 1; j<=6; j++) {
                    if(k - j <= 0) {
                        break;
                    }
                    dp[i][k] += dp[i-1][k - j] * 1.0 / 6.0;
                }
            }
        }
        vector<double> res(5 * num + 1);
        for(int i = 0; i<res.size(); i++) {
            res[i] = dp[num][num + i];
        }
        return res;
    }
};