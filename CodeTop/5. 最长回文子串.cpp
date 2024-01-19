class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool> > dp(n, vector<bool>(n,false));
        for(int i=0; i<n; i++) {
            dp[i][i] = true;
        }
        string res="";
        int maxLen = 1;
        int start = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j]) {
                    if(j-i+1 == 2) dp[i][j] = true;
                    else dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = false;
                }
                if(dp[i][j] && maxLen < j-i+1) {
                    maxLen = j-i+1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};