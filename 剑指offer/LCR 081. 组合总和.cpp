class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    int sum = 0;
    void backtrack(vector<int>& candidates, int start, int target) {
        if(sum == target) {
            res.push_back(tmp);
            return;
        }
        if(sum > target) return;
        for(int i=start; i<candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1]) continue;
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            backtrack(candidates, i, target);
            sum -= candidates[i];
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }
};