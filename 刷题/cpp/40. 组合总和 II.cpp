class Solution {
private: 
    vector<vector<int> > ans;
    vector<int> track;
public:
    void backtrack(vector<int>& candidates, int start, int score, int target) {
        if(score == target) {
            ans.push_back(track);
        }
        if(score > target) {
            return;
        }
        for(int i=start; i<candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1]) {
                continue;
            }
            track.push_back(candidates[i]);
            score += candidates[i];
            backtrack(candidates, i+1, score, target);
            track.pop_back();
            score -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, 0, target);
        return ans;
    }
};