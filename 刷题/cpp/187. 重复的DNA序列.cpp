class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        if(s.length()<=10){
            return {};
        }
        for(int i=0;i<=s.length()-10;i++){
            string str=s.substr(i,10);
            mp[str]++;
        }
        vector<string> ans;
        for(auto [k,v]: mp) {
            if(v>1){
                ans.push_back(k);
            }
        }
        return ans;
    }
};