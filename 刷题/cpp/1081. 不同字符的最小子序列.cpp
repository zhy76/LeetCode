class Solution {
public:
    unordered_map<char, int> count;
    stack<char> stk;
    unordered_map<char, bool> inStack;
    string smallestSubsequence(string s) {
        for(auto c:s) {
            count[c]++;
        }
        for(auto c:s) {
            count[c]--;
            if(inStack[c]) continue;
            while(!stk.empty() && stk.top() > c) {
                if(count[stk.top()] == 0) break;
                inStack[stk.top()] = false;
                stk.pop();
            }
            stk.push(c);
            inStack[c] = true;
        }
        string res;
        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};