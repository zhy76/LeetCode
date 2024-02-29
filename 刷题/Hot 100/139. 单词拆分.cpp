class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        unordered_set<string> st;
        for(auto word: wordDict) {
            st.insert(word);
        }
        dp[0] = true;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                string sub = s.substr(j, i-j);
                if(st.find(sub)!=st.end() && dp[j]) {
                    dp[i] = true;
                    break;
                } 
            }
        }
        return dp[n];
    }
};