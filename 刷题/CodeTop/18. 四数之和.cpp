class Solution {
public:
    vector<vector<int>> towSum(vector<int>& nums, int start, long long target) {
        int l = start, r = nums.size() - 1;
        vector<vector<int>> res;
        while(l < r) {
            long long sum = nums[l] + nums[r];
            int left = nums[l], right = nums[r];
            if(sum > target) {
                while(l < r && nums[r] == right) r--;
            } else if(sum < target) {
                while(l < r && nums[l] == left) l++;
            } else {
                res.push_back({nums[l], nums[r]});
                while(l < r && nums[l] == left) l++;
                while( l< r && nums[r] == right) r--;
            }
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int start, long long target) {
        vector<vector<int>> res;
        for(int i=start; i<nums.size(); i++) {
            vector<vector<int>> tuples = towSum(nums, i+1, target - nums[i]);
            for(auto tuple:tuples) {
                tuple.push_back(nums[i]);
                res.push_back(tuple);
                while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            vector<vector<int>> tuples = threeSum(nums, i+1, target - nums[i]);
            for(auto tuple: tuples) {
                tuple.push_back(nums[i]);
                res.push_back(tuple);
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};