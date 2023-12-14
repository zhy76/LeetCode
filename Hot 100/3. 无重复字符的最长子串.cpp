class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int ans=0;
        while(right < s.length()) {
            char c = s[right];
            right++;
            window[c]++;
            while(left < right && window[c]>1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};