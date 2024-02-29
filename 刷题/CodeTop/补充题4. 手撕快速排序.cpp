class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int i = left, j = right - 1, pivot = nums[right];
        while(true) {
            while(i <= j && nums[i] < pivot) i++;
            while(i <= j && nums[j] > pivot) j--;
            if(i > j) break;
            swap(nums[i++], nums[j--]);
        }
        swap(nums[i], nums[right]);
        return i;
    }
    void qsort(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int p = partition(nums, left, right);
        qsort(nums, p+1, right);
        qsort(nums, left, p-1);
    }
    vector<int> sortArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int index = rand() % (right - left + 1) + left;
        swap(nums[index], nums[right]);
        qsort(nums, left, right);
        return nums;
    }
};