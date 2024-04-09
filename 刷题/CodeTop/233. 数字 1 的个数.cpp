class Solution {
public:
    vector<vector<int>> dp;
    int f(string s, int ind, int cnt, bool is_limit) {
        if(ind == s.size()) {
            return cnt;
        }
        if(!is_limit && dp[ind][cnt]) return dp[ind][cnt];
        int res = 0;
        int up = is_limit ? s[ind] - '0' : 9;
        for(int d = 0; d <= up; d++) {
            res += f(s, ind + 1, cnt + (d == 1), is_limit && (d == up));
        } 
        if(!is_limit) dp[ind][cnt] = res;
        return res;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.size();
        dp = vector<vector<int>>(m, vector<int>(m, 0));
        return f(s, 0, 0, true);
    }
};