class Solution {
public:
    vector<int> box;
    bool dfs(vector<int>& nums, int k, int target, int ind) {
        if(ind == nums.size()) {
            return true;
        }
        for(int i=0; i<k; i++) {
            if(i>0 && box[i-1] == box[i]) continue;
            if(box[i] + nums[ind] > target) continue;
            box[i] += nums[ind];
            if(dfs(nums, k, target, ind + 1)) return true;
            box[i] -= nums[ind];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto num: nums) {
            sum += num;
        }
        if(sum % k != 0) return false;
        int target = sum/k;
        box.resize(k, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(nums, k, target, 0);
    }
};