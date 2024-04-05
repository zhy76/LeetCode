class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long res = 0;
        int cnt = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) cnt = 1;
            else if(i > 0 && nums[i - 1] == nums[i]) cnt = 1;
            else cnt++;
            res += cnt;
        }
        return res;
    }
};