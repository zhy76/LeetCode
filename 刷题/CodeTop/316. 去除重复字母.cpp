class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> sk;
        unordered_map<char,int> count;
        unordered_map<char,bool> inStack;
        for(auto c : s) {
            count[c]++;
        }
        for(auto c : s) {
            count[c]--;
            if(inStack[c]) continue;
            while(!sk.empty() && sk.back() > c && count[sk.back()]) {
                inStack[sk.back()] = false;
                sk.pop_back();
            }
            sk.push_back(c);
            inStack[c] = true;
        }
        return string(sk.begin(), sk.end());
    }
};