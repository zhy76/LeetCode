class Solution {
public:
    int dismantlingAction(string arr) {
        unordered_map<char, int> count;
        int res = 0;
        int l = 0, r = 0;
        while(r < arr.size()) {
            char c = arr[r];
            r++;
            count[c]++;
            while(l < r && count[c] > 1) {
                char d = arr[l];
                count[d]--;
                l++;
            }
            res = max(r - l, res);
        }
        return res;
    }
};