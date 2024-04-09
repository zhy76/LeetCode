class Solution {
public:
    vector<vector<int> > dp;
    int f(string s, int ind, int cnt, int isLimit) {
        if(ind == s.size()) {
            return cnt;
        }
        if(!isLimit && dp[ind][cnt]) return dp[ind][cnt];
        int res = 0;
        int up = isLimit ? s[ind] - '0' : 9;
        for(int d = 0; d <= up; d++) {
            res += f(s, ind + 1, cnt + (d == 1), isLimit && (d == up));
        }
        if(!isLimit) dp[ind][cnt] = res;
        return res;
    }

    int digitOneInNumber(int num) {
        string s = to_string(num);
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, 0));
        return f(s, 0, 0, true);
    }
};