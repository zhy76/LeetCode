class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        stack<int> st2;
        for(int i=n-1; i>=0; i--) {
            while(!st2.empty() && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }
            right[i] = st2.empty() ? n : st2.top();
            st2.push(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};