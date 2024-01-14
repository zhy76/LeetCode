class Solution {
public:
    stack<char> st;
    string removeKdigits(string num, int k) {
        for(auto c:num) {
            while(!st.empty() && st.top() > c && k) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k) {
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        while(res[0] == '0') {
            res.erase(res.begin());
        }
        return res == "" ? "0" : res;
    }
};