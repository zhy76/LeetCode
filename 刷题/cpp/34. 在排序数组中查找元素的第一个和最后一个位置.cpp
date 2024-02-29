class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] >= target){
                right = mid-1;
            }else {
                left = mid + 1;
            }
        }
        int ind1=left;
        left = 0, right = n - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target){
                right = mid-1;
            } else {
                left = mid + 1;
            }
        }
        int ind2=left;
        cout<<ind1<<" "<<ind2<<endl;
        if (ind1 <= ind2-1 && ind2-1 < n && nums[ind1] == target && nums[ind2-1] == target)
        return {ind1, ind2-1};
        return {-1,-1};
    }
};