class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while(left <= i && i <= right) {
            if(nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            } else if(nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                if(left > i) i = left;
            } else i++;
        }
        
    }
};