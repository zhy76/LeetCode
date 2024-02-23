class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string res = "";
        while(i < s.size()) {
            char c = s[i];
            if(c == ' ') {
                i++;
                continue;
            }
            string tmp = "";
            while(i < s.size() && s[i] != ' ') {
                tmp += s[i];
                i++;
            }
            reverse(tmp.begin(), tmp.end());
            res += tmp;
            res += " ";
            i++;
        }
        reverse(res.begin(), res.end());
        int j = 0;
        while(res[j] == ' ') {
            res.erase(res.begin());
        }
        return res;
    }
};