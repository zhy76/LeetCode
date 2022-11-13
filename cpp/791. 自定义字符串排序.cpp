class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> fre(26);
        for(char ch:s){
            fre[ch-'a']++;
        }
        string ans;
        for(char ch:order){
            if(fre[ch-'a']>0){
                ans+=string(fre[ch-'a'],ch);
                fre[ch-'a']=-0;
            }
        }
        for(int i=0;i<26;i++){
            if(fre[i]>0){
                ans+=string(fre[i],i+'a');
            }
        }
        return ans;
    }
};