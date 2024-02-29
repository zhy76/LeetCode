class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> mindp(n, 0);
        vector<int> maxdp(n, 0);
        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                mindp[i] = nums[i];
                maxdp[i] = nums[i];
                res = max(maxdp[i], res);
                continue;
            }
            maxdp[i] = max(maxdp[i-1] * nums[i], max(nums[i], mindp[i-1] * nums[i]));
            mindp[i] = min(maxdp[i-1] * nums[i], min(nums[i], mindp[i-1] * nums[i]));
            res = max(maxdp[i], res);
        }
        return res;
    }
};