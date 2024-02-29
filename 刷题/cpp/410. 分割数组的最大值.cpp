class Solution {
public:
    // 设最大子数组和为x，x越大，分的子数组越小，所以f(x)关于x单调递减
    int f(vector<int>& nums, int x) {
        // 分的子数组个数
        int num = 1;
        // 当前子数组和
        long long tmp = 0;
        for(auto y:nums) {
            tmp += y;
            // 如果当前子数组和大于最大子数组和，则再分一个子数组
            if(tmp > x) {
                num++;
                tmp = y;
            }
        }
        return num;
    }
    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(),nums.end(),0) + 1;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(f(nums, mid) <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};