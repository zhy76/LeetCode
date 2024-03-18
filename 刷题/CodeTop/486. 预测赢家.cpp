class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j][0]: [i, j]范围内作为先手可以得到的最高分数
        // dp[i][j][1]: [i, j]范围内作为后手可以得到的最高分数
        vector<vector<vector<int> > > dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        for(int i = 0; i < n; i++) {
            // 如果i == j,那么先手就拿nums[i], 后手没得拿
            dp[i][i][0] = nums[i];
            dp[i][i][1] = 0;
        } 
        // dp[i][j][0] = max(nums[i] + dp[i + 1][j][1], nums[j] + dp[i][j-1][1]);
        // dp[i][j][1] = 如果先手拿了左边，那么为dp[i + 1][j][0],否则为dp[i][j-1][0];
        // 先手要么拿左边i，要么拿右边j，如果拿左边，那么局势变为[i+1, j]，先由对方在这个区间选择，再由自己选，自己变成了后手，同理先拿右边也是一样
        // # 解释：我作为后手，要等先手先选择，有两种情况：

// # 如果先手选择了最左边那堆，给我剩下了 piles[i+1...j]
// # 此时轮到我，我变成了先手，此时的最优得分是 dp[i+1][j].fir

// # 如果先手选择了最右边那堆，给我剩下了 piles[i...j-1]
// # 此时轮到我，我变成了先手，此时的最优得分是 dp[i][j-1].fir
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++) {
                int left = nums[i] + dp[i + 1][j][1];
                int right = nums[j] + dp[i][j - 1][1];
                if(left > right) {
                    dp[i][j][0] = left;
                    dp[i][j][1] = dp[i + 1][j][0];
                } else {
                    dp[i][j][0] = right;
                    dp[i][j][1] = dp[i][j - 1][0];
                }
            }
        }
        return dp[0][n - 1][0] - dp[0][n - 1][1] >= 0;
    }
};