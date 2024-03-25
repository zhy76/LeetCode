class Solution {
public:
    vector<string> res;
    string track;
    vector<bool> used;
    void backtrack(string goods) {
        if(track.size() == goods.size()) {
            res.push_back(track);
            return;
        }
        for(int i = 0; i < goods.size(); i++) {
            if(used[i]) continue;
            if(i > 0 && goods[i] == goods[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            track.push_back(goods[i]);
            backtrack(goods);
            track.pop_back();
            used[i] = false;
        }
    }
    vector<string> goodsOrder(string goods) {
        sort(goods.begin(), goods.end());
        int n = goods.size();
        used.resize(n, false);
        backtrack(goods);
        return res;
    }
};