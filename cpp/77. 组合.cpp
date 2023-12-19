class Solution {
private:
    vector<vector<int> > ans;
    vector<int> track;
public:
    void backtrack(int n, int k, int strat) {
        if(track.size() == k) {
            ans.push_back(track);
            return;
        }
        for(int i=strat; i<=n; i++) {
            track.push_back(i);
            backtrack(n, k, i+1);
            track.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return ans;
    }
};