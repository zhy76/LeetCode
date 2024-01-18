class Solution {
public:
    int twoSumClosest(vector<int>& nums, int start, int target) {
        int l = start, r = nums.size() - 1;
        int minDiff = INT_MAX;
        int res = INT_MAX;
        while(l < r) {
            int sum = nums[l] + nums[r];
            int left = nums[l], right = nums[r];
            int diff = abs(sum - target);
            if(sum < target) {
                if(diff < minDiff) {
                    minDiff = diff;
                    res = sum; 
                }
                while(l < r && nums[l] == left) l++;
            } else if(sum > target) {
                if(diff < minDiff) {
                    minDiff = diff;
                    res = sum;
                }
                while(l < r && nums[r] == right) r--;
            } else {
                return sum;
            }
        }
        return res;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int minDiff = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            int ta = target - nums[i];
            int twoSum = twoSumClosest(nums, i+1, ta);
            if(twoSum == INT_MAX) continue;
            int threeSum = twoSum + nums[i];
            int diff = abs(threeSum - target);
            if(diff < minDiff) {
                minDiff = diff;
                res = threeSum;
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};