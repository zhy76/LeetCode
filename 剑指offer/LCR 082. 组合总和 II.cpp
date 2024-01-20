class Solution {
public:
    vector<vector<int> > res;
    vector<int> tmp;
    int sum = 0;
    void backtrack(vector<int>& candidates, int start, int target) {
        if(sum == target) {
            res.push_back(tmp);
            return;
        }
        if(sum > target) return;
        for(int i = start; i<candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, i+1, target);
            tmp.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }
};