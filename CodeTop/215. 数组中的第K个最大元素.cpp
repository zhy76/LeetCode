class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int i=left, j=right - 1, pivot = nums[right];
        while(true) {
            while(i<=j && nums[i] < pivot) i++;
            while(i<=j && nums[j] > pivot) j--;
            if(i > j) break;
            swap(nums[i++], nums[j--]); 
        }
        swap(nums[i], nums[right]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n-1;
        int index = rand() % (right - left + 1) + left;
        swap(nums[index], nums[right]);
        int kk = n-k;
        while(left <= right) {
            int p = partition(nums, left, right);
            if(p > kk) {
                right = p - 1;
            } else if(p < kk) {
                left = p + 1;
            } else{
                return nums[p];
            }
        }
        return -1;
    }
};