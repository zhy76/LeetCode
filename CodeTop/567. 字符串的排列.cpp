class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int valid = 0;
        int left = 0, right = 0;
        for(char c: s1) need[c]++;
        while(right < s2.length()) {
            char c = s2[right];
            right++;
            if(need.count(c)) {
                window[c]++;
                if(need[c] == window[c]) valid++;
            }
            while(left < right && right - left == s1.length()) {
                if(valid == need.size()) return true;
                char d = s2[left];
                left++;
                if(need.count(d)) {
                    if(need[d] == window[d]) valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};