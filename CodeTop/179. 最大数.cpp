class Solution {
public:
    struct cmp {
        bool operator () (const string& x, const string& y) {
            return x + y > y + x;
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), cmp());
        if(strs[0] == "0") return "0";
        string res = "";
        for(auto str: strs) {
            res += str;
        }
        return res;
    }
};