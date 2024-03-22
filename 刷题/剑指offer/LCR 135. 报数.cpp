class Solution {
public:
    vector<string> res;
    string tmp = "";
    void backtrack(int cnt, int ind) {
        if(ind == cnt) {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < 10; i++) {
            tmp += '0' + i;
            backtrack(cnt, ind + 1);
            tmp.pop_back();
        }
    }
    vector<int> countNumbers(int cnt) {
        vector<int> res_int;
        backtrack(cnt, 0);
        for(int i = 1; i <res.size(); i++) {
            res_int.push_back(stoi(res[i]));
        }
        return res_int;
    }
};