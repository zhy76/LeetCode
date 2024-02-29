class Solution {
public:
    vector<vector<int> > res;
    vector<int> track;
    void backtrack(vector<int>& candidates, int target, int ind, int sum) {
        if(sum == target) {
            res.push_back(track);
            return;
        }
        for(int i = ind; i < candidates.size(); i++) {
            if(sum + candidates[i] > target) continue;
            track.push_back(candidates[i]);
            backtrack(candidates, target, i, sum + candidates[i]);
            track.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0, 0);
        return res;
    }
};