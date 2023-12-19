class Solution {
private:
    vector<vector<int> > ans;
    vector<int> track;
public:
    void backtrack(vector<int>& nums, int start) {
        ans.push_back(track);
        for(int i=start; i<nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, i+1);
            track.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};