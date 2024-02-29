class Solution {
public:
    int rob(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> dp(n);
        dp[l] = nums[l];
        dp[l+1] = max(nums[l], nums[l+1]);
        for(int i=l+2; i<=r; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[r];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }
};