class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        // vector<int> window;
        int sum = 0;
        int res = n + 1;
        while(r < n) {
            // window.push_back(nums[r]);
            sum += nums[r];
            r++;
            while(l < r && sum >= target) {
                res = min(res, r - l);
                sum -= nums[l];
                // window.erase(window.begin());
                l++;
            }
        }
        return res == n+1 ? 0 : res;
    }
};