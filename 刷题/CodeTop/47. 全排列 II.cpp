class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<bool> used;
    void backtrack(vector<int>& nums) {
        if(track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }
            if(used[i]) continue;
            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums);
            used[i] = false;
            track.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }
};