class Solution {
public:
    int solve(vector<int>& nums,int pos){
        int res=0;
        for(int i=pos;i<nums.size();i+=2){
            int left=i?nums[i-1]:INT_MAX;
            int right=i<nums.size()-1?nums[i+1]:INT_MAX;
            res+=max(nums[i]-min(left,right)+1,0);
        }
        return res;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(solve(nums,0),solve(nums,1));
    }
};