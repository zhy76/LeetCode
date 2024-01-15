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
        swap(nums[r], nums[i]);
        return i;
    }

    void sort(vector<int>& nums, int l, int r) {
        if(l >= r) return;
        int index = rand()%(r - l + 1) + l;
        swap(nums[r], nums[index]);
        int k = partition(nums, l, r);
        sort(nums, l, k-1);
        sort(nums, k+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }
};