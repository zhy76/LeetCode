class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for(auto trip: trips) {
            int start = trip[1];
            int end = trip[2] - 1;
            int k = trip[0];
            diff[start] += k;
            if(end + 1 < 1001) {
                diff[end + 1] -= k;
            }
        }
        vector<int> nums(1001, 0);
        nums[0] = diff[0];
        if(nums[0] > capacity) return false;
        for(int i=1; i<=1000; i++) {
            nums[i] = nums[i-1] + diff[i];
            if(nums[i] > capacity) return false;
        }
        return true;
    }
};