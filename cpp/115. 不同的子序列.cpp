class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9+7;
        int m = s.length(), n = t.length();
        if(m < n) return 0;
        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                } else if(i == 0) {
                    dp[i][j] = 0;
                } else {
                    if(s[i-1] == t[j-1]) {
                        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};