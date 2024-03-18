class Solution {
public:
    string pathEncryption(string path) {
        string ans;
        for(auto c : path) {
            if(c == '.') {
                ans += ' ';
            } else ans += c;
        }
        return ans;
    }
};