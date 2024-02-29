class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // pre[i] = pre[i-1] + nums[i]
        // pre[i] - pre[j-1] = k
        // pre[j-1] = pre[i] - k
        int n=nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans=0, pre=0;
        for(int i=0; i<n; i++) {
            pre+=nums[i];
            if(mp.find(pre-k) != mp.end()) {
                ans+=mp[pre-k];
            }
            mp[pre]++;
        }
        return ans;
    }
};