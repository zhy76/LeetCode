// 问题1：
int getMax(vector<int>nums) {
    int n = nums.size();
    vector<vector<int> > dp(n + 1, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            dp[i][0] = 0;
            dp[i][1] = -nums[i];
        } else {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + nums[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - nums[i]);
        }
    }
    return dp[n - 1][0];
}

// 问题2：
int getMax(vector<int>nums) {
    int n = nums.size();
    vector<vector<vector<int> > > dp(n + 1, vector<int>(3, vector<int>(2, 0)));
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i == 0) {
                dp[i][j][0] = 0;
                dp[i][j][1] = -nums[i];
            } else {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + nums[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - nums[i]);
            }
        }
    }
    return dp[n - 1][2][0];
} 

// 问题3：
int getMaxNoK(vector<int>&nums) {
    int n = nums.size();
    vector<vector<int> > dp(n + 1, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            dp[i][0] = 0;
            dp[i][1] = -nums[i];
        } else {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + nums[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - nums[i]);
        }
    }
    return dp[n - 1][0];
}
int getMax(vector<int>nums, int k) {
    int n = nums.size();
    if(k > n / 2) return getMaxNoK(nums);
    vector<vector<vector<int> > > dp(n + 1, vector<int>(k + 1, vector<int>(2, 0)));
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i == 0) {
                dp[i][j][0] = 0;
                dp[i][j][1] = -nums[i];
            } else {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + nums[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - nums[i]);
            }
        }
    }
    return dp[n - 1][k][0];
}