class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num: nums){
            st.insert(num);
        }
        int ans=0;
        for(auto num: st){
            if(!st.count(num-1)){
                int len=1;
                int curnum=num;
                while(st.count(curnum+1)){
                    len++;
                    curnum++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};