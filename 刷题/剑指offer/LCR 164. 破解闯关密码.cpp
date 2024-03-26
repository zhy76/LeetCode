class Solution {
public:
    struct cmp{
        bool operator () (const string& a, const string& b) {
            return a + b < b + a;
        }
    };
    string crackPassword(vector<int>& password) {
        vector<string> ss;
        for(auto num : password) {
            ss.push_back(to_string(num));
        }
        sort(ss.begin(), ss.end(), cmp());
        return accumulate(ss.begin(), ss.end(), string(""));
    }
};