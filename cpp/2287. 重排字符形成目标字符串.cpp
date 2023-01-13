class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> sCnt,targetCnt;
        for(auto &ch:target){
            targetCnt[ch]++;
        }
        for(auto &ch:s){
            sCnt[ch]++;
        }
        int ans=INT_MAX;
        for(auto&[c,cnt]:targetCnt){
            ans=min(ans,sCnt[c]/cnt);
            if(ans==0) return 0;
        }
        return ans;
    }
};