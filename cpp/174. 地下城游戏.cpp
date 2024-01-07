class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int> > dp(n+1, vector<int>(m+1, INT_MAX));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--) {
                if(i == n-1 && j == m-1) {
                    dp[i][j] = dungeon[i][j] >=0 ? 1: -dungeon[i][j] + 1;
                    continue;
                }
                int minn = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(minn - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};