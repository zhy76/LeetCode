class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);
        for(int i = heights.size() - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        stack<int> st1;
        for(int i = 0; i < n; i++) {
            while(!st1.empty() && heights[st1.top()] >= heights[i]) {
                st1.pop();
            }
            left[i] = st1.empty() ? -1 : st1.top();
            st1.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};