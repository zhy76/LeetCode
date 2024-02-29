class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        int valid = 0;
        for(char c:t) {
            need[c]++;
        }
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;
        while(right < s.length()) {
            char c = s[right];
            right++;
            window[c]++;
            if(need.count(c) && window[c] == need[c]) {
                valid++;
            }
            while(left < right && valid == need.size()) {
                if(right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if(need.count(d) && window[d] == need[d]) {
                    valid--;
                }
                window[d]--;
            }
        }
        return len == INT_MAX?"":s.substr(start, len);
    }
};