class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto num : nums) {
            st.insert(num);
        }
        int res = 0;
        for(auto num : st) {
            if(st.count(num - 1)) continue;
            int count = 0;
            int i = num;
            while(st.count(i)) {
                count++;
                i++;
            }
            res = max(res, count);
        }
        return res;
    }
};