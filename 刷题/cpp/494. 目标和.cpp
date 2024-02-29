// 法一： 记忆化回溯
class Solution {
public:
    unordered_map<string, int> memo;
    int backtrack(vector<int>& nums, int i, int rest) {
        if(i == nums.size()) {
            if(rest == 0) {
                return 1;
            }
            return 0;
        }
        string key = to_string(i) + "," + to_string(rest);
        if(memo.count(key)) return memo[key];
        int result = backtrack(nums, i+1, rest - nums[i]) + backtrack(nums, i+1, rest + nums[i]);
        memo[key] = result;
        return result;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        return backtrack(nums, 0, target);
    }
};

// 法二：动态规划，0-1背包
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n:nums) sum+=n;
        if(sum + target < 0 || (sum + target) % 2 == 1) {
            return 0;
        }
        int amount = (sum+target) / 2;
        int n = nums.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=amount; j>=nums[i-1]; j--) {
                dp[j] = dp[j] + dp[j-nums[i-1]];
            }
        }
        return dp[amount];
    }
};