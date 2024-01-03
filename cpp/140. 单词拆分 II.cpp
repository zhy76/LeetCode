class Solution {
public:
    unordered_map<int,vector<string>> ans;
    unordered_set<string> st;
    void backtrack(string s, int ind) {
        // 找得到，则防止冗余计算
        if(ans.count(ind)) {
            return;
        }

        if(ind == s.length()) {
            ans[ind].push_back("");
            return;
        }

        for(int len=1; len+ind <= s.length(); len++) {
            string sub = s.substr(ind, len);
            if(st.find(sub) != st.end()) {
                backtrack(s, ind + len);
                for(string str: ans[ind+len]) {
                    if(str.empty()) {
                        ans[ind].push_back(sub);
                    } else {
                        ans[ind].push_back(sub + " " + str);
                    }
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s,0);
        return ans[0];
    }
};