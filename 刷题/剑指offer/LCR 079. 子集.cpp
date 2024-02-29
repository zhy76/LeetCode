class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void backtrack(vector<int>& nums, int start) {
        res.push_back(tmp);
        if(tmp.size() == nums.size()) {
            return;
        }
        for(int i=start; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(nums, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};