class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        stack<int> st;
        int i = 0;
        for(auto num : putIn) {
            st.push(num);
            while(!st.empty() && st.top() == takeOut[i]) {
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};