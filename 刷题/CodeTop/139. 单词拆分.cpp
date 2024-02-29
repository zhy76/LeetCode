class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        unordered_set<string> words;
        for(auto word : wordDict) {
            words.insert(word);
        }
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if(dp[j] && words.find(sub) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};