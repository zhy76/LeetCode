class Solution {
public:
    int crackNumber(int ciphertext) {
        string s = to_string(ciphertext);
        int n = s.size();
        vector<int> dp(n + 1, 0);
        if(n == 0) return 1;
        if(n == 1) return 1;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            char c = s[i - 1];
            dp[i] += dp[i-1];
            if(s[i - 2] == '1' || s[i - 2] == '2' && c >= '0' && c <= '5') {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};