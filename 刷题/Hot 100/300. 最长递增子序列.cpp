class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n ,0);
        if(n==0) {
            return 0;
        }
        for(int i=0; i<nums.size();i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};