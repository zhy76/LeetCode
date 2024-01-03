class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxDP(n);
        vector<int> minDP(n);
        maxDP[0] = nums[0];
        minDP[0] = nums[0];
        for(int i=1; i<n; i++) {
            maxDP[i] = max(maxDP[i-1] * nums[i], max(nums[i], minDP[i-1] * nums[i]));
            minDP[i] = min(minDP[i-1] * nums[i], min(nums[i], maxDP[i-1] * nums[i]));
        }
        return *max_element(maxDP.begin(), maxDP.end());
    }
};