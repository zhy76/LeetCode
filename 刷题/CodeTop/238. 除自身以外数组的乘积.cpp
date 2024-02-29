class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            if(i == 0) {
                ans[i] = 1;
            } else {
                ans[i] = ans[i-1] * nums[i - 1];
            }
        }
        int R = 1;
        for(int i=n-1; i>=0; i--) {
            ans[i] = ans[i] * R;
            R *= nums[i];
        }
        return ans;
    }
};