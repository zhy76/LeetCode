class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int left = (n - 1) / 2;
        int right = n - 1;
        sort(nums.begin(), nums.end());
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                res[i] = nums[left];
                left--;
            } else {
                res[i] = nums[right];
                right--;
            }
        }
        nums = res;
    }
};