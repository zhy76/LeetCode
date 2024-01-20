class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> used;
    void backtrack(vector<int>& nums) {
        if(tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(used[i]) continue;
            used[i] = true;
            tmp.push_back(nums[i]);
            backtrack(nums);
            used[i] = false;
            tmp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size());
        backtrack(nums);
        return res;
    }
};