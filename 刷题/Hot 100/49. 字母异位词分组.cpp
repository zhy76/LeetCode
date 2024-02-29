class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        unordered_map<string, vector<string> > mp;
        for(auto& str: strs) {
            string count(26, '0');
            for(auto& c: str){
                count[c-'a']+=1;
            }
            mp[count].push_back(str);
        }
        for(auto& [k, v]: mp){
            ans.push_back(v);
        }
        return ans;
    }
};