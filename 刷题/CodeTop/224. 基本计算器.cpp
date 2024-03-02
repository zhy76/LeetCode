class Solution {
public:
    int cal(deque<char>& qu) {
        stack<int> st;
        int num = 0; 
        char sign = '+';
        while(!qu.empty()) {
            char c = qu.front();
            qu.pop_front();
            if(isdigit(c)) {
                num = num * 10 +(c - '0');
            }
            if(c == '(') {
                num = cal(qu);
            }
            if((!isdigit(c) && c != ' ') || qu.empty()) {
                switch(sign) {
                    case '+': {
                        st.push(num);
                        break;
                    }
                    case '-': {
                        st.push(-num);
                        break;
                    }
                }
                sign = c;
                num = 0;
            }
            if(c == ')') {
                break;
            }
        }
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
    int calculate(string s) {
        deque<char> qu(s.begin(), s.end());
        return cal(qu);
    }
};