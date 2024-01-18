class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        int l = start, r = nums.size() - 1;
        vector<vector<int> > res;
        while(l < r) {
            int sum = nums[l] + nums[r];
            int left = nums[l], right = nums[r];
            if(sum < target) {
                while(l < r && left == nums[l]) l++;
            } else if(sum > target) {
                while(l < r && right == nums[r]) r--;
            } else if(sum == target) {
                res.push_back({nums[l], nums[r]});
                while(l < r && left == nums[l]) l++;
                while(l < r && right == nums[r]) r--;
            }
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for(int i=0; i<nums.size(); i++) {
            int target = -nums[i];
            vector<vector<int> > tuple = twoSum(nums, i+1, target);
            for(int j=0; j<tuple.size(); j++) {
                tuple[j].push_back(nums[i]);
                res.push_back(tuple[j]);
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};