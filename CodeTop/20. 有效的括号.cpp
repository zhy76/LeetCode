class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length() % 2) return false;
        for(char c:s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(c == ')') {
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else return false;
            } else if(c == '}') {
                if(!st.empty() && st.top() == '{') {
                    st.pop();
                } else return false;
            }  else if(c == ']') {
                if(!st.empty() && st.top() == '[') {
                    st.pop();
                } else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};