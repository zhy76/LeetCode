class Solution {
private:
    vector<vector<int> > ans;
    vector<int> track;
    vector<bool> used;
public:
    void backtrack(vector<int>& nums) {
        if(track.size() == nums.size()) {
            ans.push_back(track);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(used[i]) {
                continue;
            }
            if(i>0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }
            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums);
            used[i] = false;
            track.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return ans;
    }
};