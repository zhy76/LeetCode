class Solution {
public:
    string encode(string s) {
        vector<int> count(26, 0);
        for(auto c:s) {
            count[c - 'a']++;
        }
        string code = string(count.begin(), count.end());
        return code;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string> > res;
        for(auto str:strs) {
            mp[encode(str)].push_back(str);
        }
        for(auto [k,v]:mp) {
            res.push_back(v);
        }
        return res;
    }
};