class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-k]
        // return dp[n][target]
        int MOD=1000000007;
        // vector<vector<int> > dp(n+1, vector<int>(target+1));
        vector<int> dp(target+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            vector<int> g(target+1);
            for(int j=1;j<=target;j++){
                for(int h=1;h<=k && j>=h;h++){
                    g[j]=(g[j]+dp[j-h])%MOD;
                }
            }
            dp=move(g);
        }
        return dp[target];
    }
};