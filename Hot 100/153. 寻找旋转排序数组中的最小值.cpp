class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int low = 0, high = n - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] < nums[low]) {
                high = mid;
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                break;
            }
        }
        return nums[low];
    }
};