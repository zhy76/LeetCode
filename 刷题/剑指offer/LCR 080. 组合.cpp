class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void backtrack(int start, int k, int n) {
        if(tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        for(int i=start; i<=n; i++) {
            tmp.push_back(i);
            backtrack(i+1, k, n);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(1, k, n);
        return res;
    }
};