class Solution {
public:
    string decodeString(string s) {
        string strNum = "";
        string strChar = "";
        stack<string> st;
        for(char c: s) {
            if(c>='0' && c<='9') {
                strNum += c;
            }
            if((c>='a' && c<='z') || (c>='A' && c<='Z')) {
                strChar += c;
            }
            if(c == '[') {
                st.push(strNum);
                strNum = "";
                st.push(strChar);
                strChar = "";
            }
            if(c == ']') {
                string top = st.top();
                st.pop();
                string times = st.top();
                st.pop();
                int itimes = atoi(times.c_str());
                for(int i = 0; i < itimes; i++) {
                    top += strChar;
                }
                strChar = top;
            }
        }
        return strChar;
    }
};