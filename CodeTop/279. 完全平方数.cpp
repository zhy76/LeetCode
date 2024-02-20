class Solution {
public:
    int numSquares(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n; i++) {
            dp[i] = i;
            for(int j = 1; i - j*j >=0; j++) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};