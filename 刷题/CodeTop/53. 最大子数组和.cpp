class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int res = dp;
        for(int i=1; i<nums.size(); i++) {
            dp = max(nums[i], dp + nums[i]);
            res = max(res, dp);
        }
        return res;
    }
};