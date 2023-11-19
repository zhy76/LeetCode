class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen=s.size(),plen=p.size();
        if(slen<plen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> scount(26);
        vector<int> pcount(26);
        for(int i=0;i<plen;i++){
            scount[s[i]-'a']++;
            pcount[p[i]-'a']++;
        }
        if(scount == pcount){
            ans.push_back(0);
        }
        for(int i=0;i<slen-plen;i++){
            --scount[s[i]-'a'];
            ++scount[s[i+plen]-'a'];
            if(scount == pcount){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};