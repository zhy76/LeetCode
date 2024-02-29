class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size(),minNum=nums[n-1];
        for(int i=n-3;i>=0;i--){
            if(nums[i]>minNum){
                return false;
            }
            minNum=min(minNum,nums[i+1]);
        }
        return true;
    }
};