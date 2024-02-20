class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int res = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++) {
            if(s[i] == ')' && s[i-1] == '(') {
                dp[i] = (i-2 >=0) ? dp[i-2] + 2 : 2;
            } 
            else if(s[i] == ')' && s[i-1] == ')') {
                if(i-dp[i-1] > 0 && s[i-1-dp[i-1]] == '(')
                dp[i] = dp[i-1] + ((i-dp[i-1]-2)>=0 ? dp[i-dp[i-1]-2]:0) + 2;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};