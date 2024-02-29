class Solution {
public:
    vector<vector<string>> res;
    vector<string> track;
    bool check(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string s, int ind) {
        if(ind == s.length()) {
            res.push_back(track);
            return;
        }
        for(int i = ind; i < s.length(); i++) {
            if(!check(s.substr(ind, i - ind + 1))) {
                continue;
            }
            track.push_back(s.substr(ind, i - ind + 1));
            backtrack(s, i + 1);
            track.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};