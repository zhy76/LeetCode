class Solution {
public:
    vector<vector<int> > res;
    vector<int> tmp;
    void dfs(vector<int>& candidates, int target, int ind){
        if(target==0){
            res.push_back(tmp);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]>target) break;
            tmp.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i);
            tmp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return res;
    }
};