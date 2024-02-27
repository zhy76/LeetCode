class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size();) {
            int num = nums[i];
            if(i + 1 < nums.size() && nums[i+1] == num) {
                int j = i + 2;
                while(j < nums.size() && nums[j] == num) {
                    nums.erase(nums.begin() + j);
                    // cout<<j<<endl;
                    // j++;
                }
                i = j - 1;
            }
            i++;
        }
        return nums.size();
    }
};