class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int i = l, j = r - 1, pivot = nums[r];
        while(true) {
            while(i<=j && nums[i] < pivot) i++;
            while(i<=j && nums[j] > pivot) j--;
            if(i>j) break;
            swap(nums[i++], nums[j--]);
        }
        swap(nums[i], nums[r]);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int kk = nums.size() - k;
        while(l<=r) {
            int p=partition(nums, l, r);
            if(p < kk) {
                l = p + 1;
            } else if(p > kk) {
                r = p -1; 
            } else {
                return nums[p];
            }
        }
        return -1;
    }
};