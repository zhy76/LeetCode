class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);
        for(int i = temperatures.size() - 1; i >=0; i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            res[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return res;
    }
};