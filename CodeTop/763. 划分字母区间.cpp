class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            last[c] = i;
        }
        int far = 0;
        vector<int> res;
        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(i <= far) {
                num++;
            } else {
                res.push_back(num);
                num = 1;
            }
            far = max(far, last[c]);
        }
        res.push_back(num);
        return res;
    }
};