class Solution {
public:
    vector<string> res;
    unordered_map<int, string> table = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    string track;
    void backtrack(string digits, int ind) {
        if(track.size() == digits.length()) {
            res.push_back(track);
            return;
        }
        for(int i = ind; i < digits.size(); i++) {
            for(auto c : table[digits[i] - '1' + 1]) {
                track.push_back(c);
                backtrack(digits, i + 1);
                track.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        backtrack(digits, 0);
        return res;
    }
};