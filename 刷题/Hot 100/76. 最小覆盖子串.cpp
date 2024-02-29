class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int left = 0, right = 0;
        for(auto c : t) {
            need[c]++;
        }
        int start = 0, len = INT_MAX;
        int valid = 0;
        while(right < s.length()) {
            char c = s[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]) {
                    valid++;
                }
            }
            while(valid == need.size()) {
                if(right - left < len) {
                    len = right - left;
                    start = left;
                }
                char d = s[left];
                left++;
                if(need.count(d)) {
                   if(window[d] == need[d]){
                       valid--;
                   }
                   window[d]--;
                }                
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};