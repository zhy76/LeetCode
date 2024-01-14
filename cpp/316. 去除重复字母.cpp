class Solution {
public:
    stack<char> sk;
    unordered_map<char, int> count;
    unordered_map<char, bool> inStack;
    string removeDuplicateLetters(string s) {
        for(auto c:s) {
            count[c]++;
        }
        for(auto c:s) {
            count[c]--;
            if(inStack[c]) continue;
            while(!sk.empty() && sk.top() > c) {
                if(count[sk.top()] == 0) break;
                inStack[sk.top()] = false;
                sk.pop();
            }
            sk.push(c);
            inStack[c] = true;
        }
        string res;
        while(!sk.empty()) {
            res += sk.top();
            sk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};