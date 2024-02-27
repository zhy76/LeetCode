class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            if(!isdigit(c) && s[i] != ' ' || i == s.size() - 1){
                switch(sign) {
                    case '+': {
                        st.push(num);
                        break;
                    }
                    case '-': {
                        st.push(-num);
                        break;
                    }
                    case '*': {
                        int pre = st.top();
                        st.pop();
                        st.push(pre * num);
                        break;
                    }
                    case '/': {
                        int pre = st.top();
                        st.pop();
                        st.push(pre / num);
                        break;
                    }
                }
                sign = c;
                num = 0;
            }
        }
        int res = 0;
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};