class Solution {
public:
    vector<string> res;
    string track;
    void backtrack(int left, int right) {
        if(left == 0 && right == 0) {
            res.push_back(track);
        }
        if(left > right) return;
        if(left < 0 || right < 0) return;

        track.push_back('(');
        backtrack(left-1, right);
        track.pop_back();

        track.push_back(')');
        backtrack(left, right - 1);
        track.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n, n);
        return res;
    }
};