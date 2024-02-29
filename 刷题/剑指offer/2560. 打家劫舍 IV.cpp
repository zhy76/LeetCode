class Solution {
public:
    // 当偷走最大金额为x时，能偷的房子最大数为f(x)
    int f(vector<int>& nums, int x) {
        int n = nums.size();
        if(n == 1) return nums[0] > x? 0:1;
        vector<int> dp(n);
        dp[0] = nums[0] > x? 0:1;
        dp[1] = nums[1] > x? dp[0]: 1;
        for(int i=2; i<n; i++) {
            if(nums[i] > x) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = max(dp[i-1], dp[i-2] + 1);
            }
        }
        return dp[n-1];
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(f(nums, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

// 降维
class Solution {
public:
    // 当偷走最大金额为x时，能偷的房子最大数为f(x)
    int f(vector<int>& nums, int x) {
        int n = nums.size();
        if(n == 1) return nums[0] > x? 0:1;
        int dp1 = nums[0] > x? 0:1;
        int dp2 = nums[1] > x? dp1: 1;
        for(int i=2; i<n; i++) {
            int dp = 0;
            if(nums[i] > x) {
                dp = dp2;
            } else {
                dp = max(dp2, dp1 + 1);
            }
            dp1 = dp2;
            dp2 = dp;
        }
        return dp2;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = *max_element(nums.begin(), nums.end());
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(f(nums, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};