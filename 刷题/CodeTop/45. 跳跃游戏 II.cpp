class Solution {
public:
    int jump(vector<int>& nums) {
        int end = 0;
        int far = 0;
        int step = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            far = max(far, nums[i] + i);
            if(i == end) {
                step++;
                end = far;
            }
        }
        return step;
    }
};