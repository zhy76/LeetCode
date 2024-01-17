class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need; // p中字符及其出现的次数
        unordered_map<char, int> window; // 窗口中包含p中字符的字符出现的次数
        int valid = 0; // 窗口中满足 need 条件的字符个数
        int left = 0,right = 0;
        for(char c: p) need[c]++;
        vector<int> res;
        while(right < s.length()) {
            int c = s[right];
            right++;
            if(need.count(c)) {
                window[c]++;
                if(window[c] == need[c]) valid++;
            }
            while(left < right && right - left == p.length()) {
                if(valid == need.size()) res.push_back(left);
                char d = s[left];
                left++;
                if(need.count(d)) {
                    if(window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return res;
    }
};