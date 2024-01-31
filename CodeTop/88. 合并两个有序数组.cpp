class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m-1, r = n-1;
        int tail = m+n-1;
        while(l>=0 || r>=0) {
            if(l < 0) {
                nums1[tail--] = nums2[r--];
            } else if(r < 0) {
                nums1[tail--] = nums1[l--];
            } else if(nums1[l] > nums2[r]) {
                nums1[tail--] = nums1[l--];
            } else nums1[tail--] = nums2[r--];
        }
    }
};