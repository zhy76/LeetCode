class Solution {
public:
    int left_search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                r = mid;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if(l < 0 || l >= nums.size()) return -1;
        return nums[l] == target ? l: -1;
    }
    int right_search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                l = mid + 1;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if(l - 1 < 0 || l - 1 >= nums.size()) return -1;
        return nums[l - 1] == target ? l - 1: -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = left_search(nums, target);
        int end = right_search(nums, target);
        return {start, end};
    }
};