class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int res = 0;
        for(auto num:nums) {
            st.insert(num);
        }
        for(auto num:st) {
            if(st.contains(num-1)) continue;
            int t = num;
            int len = 1;
            while(st.contains(t + 1)) {
                len++;
                t++;
            }
            res = max(res, len);
        }
        return res;
    }
};