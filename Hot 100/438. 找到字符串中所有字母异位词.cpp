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

// 法2
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int valid = 0;
        vector<int> ans;
        for(auto c:p){
            need[c]++;
        }
        while(right < s.length()) {
            char c = s[right];
            right++;
            if(need.count(c)) {
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }
            while(left<right && right - left == p.size()) {
                if(valid == need.size()) {
                    ans.push_back(left);
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(need[d] == window[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return ans;
    }
};