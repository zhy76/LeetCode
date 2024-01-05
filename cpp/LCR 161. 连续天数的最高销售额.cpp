class Solution {
public:
    int maxSales(vector<int>& nums) {
        int left = 0, right = 0;
        int windowSum = 0, ans = INT_MIN;
        while(right < nums.size()) {
            windowSum+=nums[right];
            right++;

            ans = max(ans, windowSum);

            while(windowSum<0) {
                windowSum-=nums[left];
                left++;
            }
        }
        return ans;
    }
};