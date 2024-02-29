class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        if(sum % 2 == 1) return false;
        int amount = sum / 2;
        int n = nums.size();
        vector<vector<bool> > dp(n, vector<bool>(amount+1, false));
        for(int i = 0; i<n; i++) {
            dp[i][0] = true;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j - nums[i] < 0) {
                    dp[i][j] = dp[i-1][j];
                } else 
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];
            }
        }
        return dp[n - 1][amount];
    }
};