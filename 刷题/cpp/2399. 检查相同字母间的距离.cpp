class Solution {
private:
    int mp[26];
public:
    bool checkDistances(string s, vector<int>& distance) {
        for(int i=0;i<26;i++){
            mp[i]=-1;
        }
        for(int i=0;i<s.length();i++){
            int t=s[i]-'a';
            if (mp[t]!=-1) mp[t]=i-mp[t]-1;
            else mp[t]=i;
        }
        for(int i=0;i<26;i++){
            if(mp[i]==distance[i]) continue;
            else if(mp[i]!=-1) return false;
        }
        return true;
    }
};