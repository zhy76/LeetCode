class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        vector<string> ss(numRows);
        int flag = -1;
        int i = 0;
        for(auto c : s) {
            ss[i].push_back(c);
            if(i == 0 || i == numRows - 1) flag = -flag;
            i += flag;
        }
        string res;
        for(string t : ss) {
            res += t;
        }
        return res;
    }
};