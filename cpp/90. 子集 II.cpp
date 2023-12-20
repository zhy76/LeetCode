class Solution {
private:
    vector<vector<int> > ans;
    vector<int> track;
public:
    void backtrack(vector<int>& nums, int start) {
        ans.push_back(track);
        for(int i=start; i<nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, i + 1);
            track.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums, 0);
        return ans;
    }
};