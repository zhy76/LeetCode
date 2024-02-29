class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        // pre[i] = pre[i-1] + nums[i-1];
        // sum[j...i] = pre[i+1] - pre[j] =k;
        // pre[j] = pre[i+1] - k;
        // 即为求有多少个j满足以i为结尾的连续和为k
        int res = 0;
        int pre = 0;
        count[pre]=1;
        for(int i=1; i<=n; i++) {
            pre = pre +nums[i-1];
            res += count[pre - k];
            count[pre]++;
        }
        return res;
    }
};