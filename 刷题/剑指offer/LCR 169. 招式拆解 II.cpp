class Solution {
public:
    char dismantlingAction(string arr) {
        unordered_map<char, int> mp;
        for(auto c : arr) {
            mp[c]++;
        }
        for(auto c : arr) {
            if(mp[c] == 1) return c;
        }
        return ' ';
    }
};